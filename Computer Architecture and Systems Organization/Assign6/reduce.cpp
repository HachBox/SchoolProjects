/*
 * CSCI 463 Assignment 6 - C++ Multithreading
 *
 * Author: Harry Chieng
 *
 * **********************************************************************************/

#include <mutex>
#include <vector>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <sstream>

using std::cerr;
using std::endl;
using std::cout;
using std::istringstream;
using std::thread;
using std::vector;

constexpr int rows = 1000; /// < the number of rows in the work matrix
constexpr int cols = 100; /// < the number of cols in the work matrix

std::mutex stdout_lock ; /// < for serializing access to stdout

std::mutex counter_lock ; /// < for dynamic balancing only
volatile int counter = rows ; /// < for dynamic balancing only

std::vector<int> tcount ; /// < count of rows summed for each thread
std::vector<uint64_t> sum ; /// < the calculated sum from each thread

int work [rows][cols]; /// < the matrix to be summed

/*
 * logic needed to sum the rows of the matrix using "static" load balancing determine which rows will be procesed by each thread.
 *
 * @param tid tid is the thread ID from main passed into sum_static.
 *
 * @param num_threads The num_threads shows the number of threads.
 *
 * @notes Ensure that certain parts that are global variables are locked, meddled with then unlocked.
 *
 * *****************************************************************************************/
void sum_static(int tid, int num_threads) {
	//use the thread ID (passed in from main()) to determine the first row 
	//for each thread and then advance the row number by "num_threads" to determine the next row to process
	stdout_lock.lock();
	cout << "Thread " << tid << " starting" << endl;
	stdout_lock.unlock();
	for(int row = tid; row < rows; row+=num_threads) {
		++tcount[tid];	//count the number of work units that this thread has done
		for(int col = 0; col < cols; col+=1) {
			sum[tid] = sum[tid] + work[row][col];
		}
	}
	stdout_lock.lock();
	cout << "thread " << tid << " ending" 
		<< " tcount=" << tcount[tid] 
		<< " sum=" << sum[tid] << endl;
	stdout_lock.unlock();
}

/* 
 * Implement the logic needed to sum the rows of the matrix using "dynamic" load balancing to determine which rows will be processed by each thread.
 *
 * @param tid tid is the thread ID from main passed into sum_dynamic.
 *
 * @notes Ensure that certain parts that are global variables are locked, meddled with then unlocked.
 *
 * *******************************************************************************************/
void sum_dynamic(int tid) {
	//each thread must use a mutex lock to access the global (and volatile) "counter" variabe in the critical section  to detemine next row to process
	//Do not hold the lock for any more of the thread logic than is absolutely necessary.
	stdout_lock.lock();
	cout << "Thread " << tid << " starting" << endl;
	stdout_lock.unlock();

	int count_copy;
	bool done = false;
	while(!done) {

		counter_lock.lock();
		{
			if(counter>0)
				--counter;
			else
				done = true;
			count_copy = counter;
		}
		counter_lock.unlock();	//grab a copy that we know is consistent w/ done flag!

		if(!done) {
			//do work using the value of count_copy to determine what to do!
			//(void)count_copy	 //remove compiler warning
			for(int col = 0; col < cols; col+=1)
				sum[tid] = sum[tid] + work[count_copy][col];
			++tcount[tid];	//count the number of work units that this thread has done
		}
	}
	stdout_lock.lock();
	cout << "Thread " << tid << " ending" << " tcount=" << tcount[tid] << " sum=" << sum[tid] << endl;
	stdout_lock.unlock();
}

void usage() {
	cerr << "Usage: reduce [-d] [-t num] infile" << endl;
	cerr << "    -d Use dynamic load-balancing, use default static load balancing" << endl;
	cerr << "    -t num Specifies the number of threads to use, by default, start two threads" << endl;
	exit (1);
}

/*
 * The main function accepts the command-line parameters with -d, and -t num
 *
 * @param argc An integer that contains the count of arguments that follow in argv. Always >= 1.
 *
 * @param argv An array of null-terminated strings representing command-line arguments entered by
 * the user of the program. 
 *
 * @note Use std::thread::hardware_concurrency() to utilize the threads used from the computer.
 *
 * ***********************************************************************************************/
int main(int argc, char **argv) {

	int opt;
	bool dvar = false;
	unsigned int  numThreads = 2;
	while((opt = getopt(argc, argv, "dt:")) != -1) {
		switch(opt) {
			case 'd':  
				{
					dvar = true;
				}	
				break;
			case 't':
				{
					istringstream iss(optarg);
					iss >> numThreads;
				}
				break;
			default:
				{
					usage();	
				}
		}
	}
	if (optind !=  argc) {
		cerr << "Error here" << endl;
		usage(); 
	}
	if (numThreads > std::thread::hardware_concurrency())
		numThreads = std::thread::hardware_concurrency();

	//Print the number of cores in the CPU that is running this program
	cout << std::thread::hardware_concurrency() << " concurrent threads supported." << endl;

	/* assert(argc == 2 &&  "missing arg");	//lazy checking of cli arg count

	   int num = stoi(argv[1]); // MF: This is part of -t, we don't need a second copy */

	// give work some values
	srand(0x1234);
	for(int row = 0; row < rows; row++)
		for(int col = 0; col < cols; col++)
			work[row][col] = rand();

	//give `sum` some values
	sum.resize(numThreads, 0);
	tcount.resize(numThreads, 0);

	vector<thread*> threads;
	if(dvar == true) { //dynamic

		for(unsigned int i = 0; i < numThreads; ++i) {
			threads.push_back(new thread(sum_dynamic, i));
		}
	}
	else { //static
		for(unsigned int i = 0; i < numThreads; ++i) {
			threads.push_back(new thread(sum_static, i, numThreads));
		}
	}
	for(unsigned int i = 0; i < numThreads; ++i) {
		threads.at(i)->join();
		delete threads.at(i);
	}

	uint64_t gross_sum = 0;
	for(uint64_t i = 0; i < sum.size(); i++)
		gross_sum+= sum[i];
	int total_work = 0;
	for(uint64_t i = 0; i < tcount.size(); i++)
		total_work+= tcount[i];
	cout << "main() exiting, total_work="
		<< total_work
		<< " gross_sum=" 
		<< gross_sum << endl;
	return 0;
}
