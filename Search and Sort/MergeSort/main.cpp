/*
	Algorithm:	Merge Sort
	Implementation:	C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void merge(int arr[], int left, int middle, int right)
{
	int i, j, k;
	int left_side = middle - left + 1;
	int right_side = right - middle;

	int L[left_side], R[right_side];
        
	for (int i = 0; i < left_side; i++)
            L[i] = arr[left + i];        
        for (int j = 0; j < right_side; j++)
            R[j] = arr[middle + 1 + j];
        
        i=0, j=0, k=left;
        
        while(i < left_side && j < right_side) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while(i < left_side) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while(j < right_side) {
            arr[k] = R[j];
            j++;
            k++;
        }     
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right) {
        int m = left+(right - left)/2;
        mergeSort(arr, left, m);
        mergeSort(arr, m+1, right);        
        merge(arr, left, m, right);
    }
}

void printArray(int arr[], int size) 
{
	for (int index = 0; index < size; index++)
		std::cout << arr[index] << " ";
	std::cout << std::endl;
}

int main()
{
        int numberOfIntegers = 0;
        std::cout << "Number of test cases: ";
        int testCases = 0;
        std::cin >> testCases;
        while(testCases--) {
        std::cout << "Number of integers to pass to array: ";
        std::cin >> numberOfIntegers;
        int arr[numberOfIntegers];
        int numbers;
        for(int i = 0; i < numberOfIntegers; i++){
            if(i == 0) {
                std::cout << "Enter " << numberOfIntegers << " numbers";
            }
            
           std::cin >> numbers; 
           arr[i] = numbers;
        }
        int newNumb = sizeof(arr)/sizeof(arr[0]);
        
        printArray(arr, newNumb);        
        mergeSort(arr, 0, newNumb -1);               
        printArray(arr, newNumb);
        
        }
      
	return 0;
}
