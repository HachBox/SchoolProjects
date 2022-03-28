/*************************************************************
Program:	CSCI 241 Assign 8
Programmer: 	Harry Chieng
Logon ID:	z1811457
Due Date:	11/29/2017
*************************************************************/

#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <iostream>
#include "sorts.h"

template <class T>
int partition(std::vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int pivotIndex, mid;	//function selects a pivot element and then partitions the vector around the pivot. The logic is
   T pivotValue;
   T tempValue; 
   mid = (start + end) / 2;
   
   tempValue = set[start];
   set[start] = set[mid];
   set[mid] = tempValue;	//to mid, we assign the value of tempValue
   //Swap elements start and mid of the vector
   pivotIndex = start;
   pivotValue = set[start];
 
   for (int scan = start + 1; scan <= end; scan++)
      {
      if (compare(set[scan], pivotValue))
         {
         pivotIndex++;
	 tempValue = set[pivotIndex];
	 set[pivotIndex] = set[scan];
	 set[scan] = tempValue;
         //Swap elements pivotIndex and scan of the vector
         }
      }
   tempValue= set[start];
   set[start] = set[pivotIndex];
   set[pivotIndex] = tempValue;
   //Swap elements start and pivotIndex of the vector

   return pivotIndex;
}

template <class T>
void quickSort(std::vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int pivotPoint;

   if (start < end)
      {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      }
}

template <class T>
void quickSort(std::vector<T>& set, bool (*compare)(const T&, const T&))
{
quickSort(set, 0, set.size()-1, compare);
}
#endif
