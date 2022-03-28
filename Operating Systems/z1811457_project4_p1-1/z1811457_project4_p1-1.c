#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#include <string.h>

//global variables
int read_count = 0;
char* str = "All work and no play makes Jack a dull boy.";
sem_t rw_sem; //used by both readers and writers
sem_t cs_sem; //used for protecting critical sections of readers

/*
   int main(int argc, char *argv[])
   {
//Get command line arguments.
//Initialization of semaphores.		pthread_attr_init(...)
//Create reader and writer threads.	pthread_create(...)
//Wait for reader threads to finish.	pthread_join(...) or wait()
//Wait for writer threads to finish.	pthread_join(...) or wait()
//Cleanup and exit.			pthread_exit(...)
}

//main program
get the # of reader and writer threads from cmd line
initialize your semaphores, use sem_init()
create your threads & error check
wait for readers threads to finish, use pthread_join()
wait for writer threads to finish, same ^^^^
then use pthread_exit() to exit
*/

//writer function
void* writer(void* thread_id_writer){

	//loop while str isn't empty
	while(str[0] != '\0') {
		printf("%s\n" ,str);
		int i = strlen(str)-1; 
		str[i] = '\0';

		//writing (chopping off last char)
		//sleep for 1 second
	}
	//note: you need to use rw_sem semaphore when writing in the loop
	pthread_exit(0);
}

//reader function
void* reader(void* threadID){
	//loop while str isn't empty
	//chop off last character of str
	//sleep for 1 second
	//note: you need to use cs_sem semaphore when reading in the loop
	pthread_exit(0);
}

int main(int argc, char *argv[]) {

	if (argc != 2)
	{
		fprintf(stderr,"usage: %s <integer value>\n",argv[0]);
		return -1;
	}

	int rw_threads = atoi(argv[1]);

	if (rw_threads < 0)
	{
		fprintf(stderr,"%d must be>= 0\n",rw_threads);
		return -1;
	}

	/*these two lines are added for initializing both to 1*/
	sem_init(&rw_sem, 0, 1);
	sem_init(&cs_sem, 0, 1);

	pthread_t thread_id_writer;
	pthread_t thread_id_reader;
	pthread_attr_t attr;

	for(long i = 0; i < rw_threads; i++) {
		int w = pthread_create(&thread_id_writer, &attr, &writer, (void*)i);
		if (w != 0) {
			perror("pthread_create");	
			exit(EXIT_FAILURE);
		}
	}

	long r = pthread_create(&thread_id_reader, &attr, &reader, (void*)thread_id_reader);
	if (r != 0) {
		perror("pthread_create");	
		exit(EXIT_FAILURE);
	}

	pthread_join(thread_id_writer, NULL);
	pthread_join(thread_id_reader, NULL); 
}
/*

   int sum; // this data is shared by the thread(s)
   int main(int argc, char *argv[])
   {

   pthread_t tid;  the thread identifier 
   pthread_attr_t attr;  set of thread attributes 

   if (argc != 2)
   {
   fprintf(stderr,"usage: a.out <integer value>\n");
   return -1;
   }

   if (atoi(argv[1]) < 0)
   {
   fprintf(stderr,"%d must be>= 0\n",atoi(argv[1]));
   return -1;
   }

   set the default attributes 
   pthread_attr_init(&attr);
   create the thread 
   pthread_create(&tid,&attr,runner,argv[1]);

   wait for the thread to exit, this joins the parent (main) and child (runner) 
   pthread_join(tid,NULL);
   printf("sum = %d\n",sum); //print the shared data sum
   }

   The thread will begin control in this function
   void *runner(void *param)
   {
   int i, upper= atoi(param); // Note from instructor: to compile on turing, need to first cast param to (char*): atoi ((char *) param)
   sum = 0;
   for (i = 1; i <= upper; i++)
   sum += i;
   pthread_exit (0) ;
   }

*/
