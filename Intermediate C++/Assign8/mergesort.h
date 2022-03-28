/*************************************************************
Program:	CSCI 241 Assign 8
Programmer: 	Harry Chieng
Logon ID:	z1811457
Due Date:	11/29/2017
*************************************************************/
#ifndef _MERGESORT_H
#define _MERGESORT_H

#include <iostream>

template <class T>
void merge(std::vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
// Create temporary std::vector to hold merged substd::vectors
   std::vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted substd::vector
   int j = mid+1;    // Subscript for start of right sorted substd::vector
   int k = 0;        // Subscript for start of merged std::vector

   // While not at the end of either substd::vector
   while (i <= mid && j <= high)
      {
      if (compare(set[j], set[i]))
         {
         temp[k] = set[j];	//Copy element j of set into element k of temp
         ++j;	//Add one to j 
         ++k;	//Add one to k
         }
      else
         {
         temp[k] = set[i];	//Copy element i of set into element k of temp
         ++i;	//Add one to i
         ++k;	//Add one to k
         }
      }

   // Copy over any remaining elements of left substd::vector
   while (i <= mid)
      {
      temp[k] = set[i];	//Copy element i of set into element k of temp
      ++i;	//Add one to i
      ++k;	//Add one to k 
      }

   // Copy over any remaining elements of right substd::vector
   while (j <= high)
      {
      temp[k] = set[j];	//Copy element j of set into element k of temp
      ++j;	//Add one to j 
      ++k;	//Add one to k
      }

   // Copy merged elements back into original std::vector
   for (i = 0, j = low; j <= high; i++, j++)
      set[j] = temp[i];	//Copy element i of temp into element j of set
}

template <class T>
void mergeSort(std::vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		// Divide and conquer
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid+1, high, compare);

		// Combine
		merge(set, low, mid, high, compare);
	}
}

template <class T>
void mergeSort(std::vector<T>& set, bool (*compare)(const T&, const T&))
{
mergeSort(set, 0, set.size()-1, compare);
}

#endif
