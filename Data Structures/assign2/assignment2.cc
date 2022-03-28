#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

int random_number() {
	return rand()%200 + 1;	//indicates the range of random numbers generated
}

void genRndNums( vector<int>& v, int seed ) {
	srand(seed);	//calls srand function with value seed 
	generate(v.begin(), v.end(), random_number);	//uses function random_number to get the range
}

bool linearSearch( const vector<int>& inputVec, int x) {
	for (auto i = 0; i < inputVec.size(); i++) {	//searches through inputVec
		if(x == inputVec[i])	//if returned true
			return true;	//return true
	}
	return false;	//returns false
}

bool binarySearch( const vector<int>& inputVec, int x) {
	int low = 0;	//initializing stuff
	int high = inputVec.size() - 1;
	int mid;

	while (low <= high) {		//while low is less than or equal to high
		mid = (low + high) / 2;	//initializing the mid
		if (x == inputVec[mid])	//if x equals inputVec's mid
			return true;	//return true
		if (x < inputVec[mid])	//if x is less than the mid
			high = mid - 1;	//high would equal mid - 1
		else
			low = mid + 1;	//else low would equal mid + 1
	}
	return false;
}

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ) {
	int goodSearches = 0;
	for(auto&num:searchVec)	//loops through each element in searchVec and puts in num
		if(p(inputVec,num))	//if the function returns true
			goodSearches++;	//increment goodSearches + 1
	return goodSearches;
}

void sortVector (vector<int>& inputVec) {
	sort(inputVec.begin(),inputVec.end());	//calls the sort function
}

void printStat (int totalSucCnt, int vec_size) {
	cout << "Successful searches: " 
	     << setprecision(2)	//sets the precision of the data to 2 numbers
	     << fixed 
	     << ( ( (float) totalSucCnt) /vec_size*100 ) << "%" << endl;	//does the math lul	
}

void print_vec( const vector<int>& vec ){
	for(auto i = 0; i < vec.size(); ++i) {
		cout << setw(6) << vec[i] << " ";	//ITEM_W = 6
		if((i+1)%10 == 0)	//NO_ITEMS = 10
			cout << endl;	//new line
			}
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

