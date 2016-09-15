/*
	Algorithm:	Merge Sort
	Implementation:	C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];
        
	for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];        
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
        
        i=0, j=0, k=l;
        
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while(i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while(j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }     
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r) {
        int m = l+(r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);        
        merge(arr, l, m, r);
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
