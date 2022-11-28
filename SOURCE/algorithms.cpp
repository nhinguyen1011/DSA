#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 1.SelectionSort
void selectionSortWithComparison(int a[], int n, unsigned long long &count_compare)
{
   
}

void selectionSortWithTime(int a[], int n)
{
    
}

// 2. InsertionSort
void insertionSortWithComparison(int arr[], int n, unsigned long long &compareCountInsert)
{
    int i, key, j;
   	for (i = 1; ++compareCountInsert && i < n; i++)
    	{
        	key = arr[i];
        	j = i - 1;
 
        	/* Move elements of arr[0..i-1], that are
        	greater than key, to one position ahead
        	of their current position */
        	while ((++compareCountInsert && j >= 0) && (++compareCountInsert && arr[j] > key))
       	{
            	arr[j + 1] = arr[j];
            	j = j - 1;
       	}
       	
        	arr[j + 1] = key;
    	}
}

void insertionSortWithTime(int arr[], int n)
{
    int i, key, j;
   	for (i = 1; i < n; i++)
    	{
        	key = arr[i];
        	j = i - 1;
 
        	/* Move elements of arr[0..i-1], that are
        	greater than key, to one position ahead
        	of their current position */
        	while (j >= 0 && arr[j] > key)
       	{
            	arr[j + 1] = arr[j];
            	j = j - 1;
       	}
       	
        	arr[j + 1] = key;
    	}
}

// 3. BubbleSort
void bubbleSortWithTime(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)    
	{
	    // Last i elements are already in place
	    	for (j = 0; j < (n - i - 1); j++)
	        	if (a[j] > a[j + 1])
	      		swap(a[j], a[j + 1]);
	}    
}

void bubbleSortWithComparison(int a[], int n, unsigned long long &compareCountBubble)
{
	int i, j;
	for (i = 0; ++compareCountBubble && i < n - 1; i++)    
	{
	    // Last i elements are already in place
	    	for (j = 0; ++compareCountBubble && j < (n - i - 1); j++)
	        	if (++compareCountBubble && a[j] > a[j + 1])
	      		swap(a[j], a[j + 1]);
	}      
}

// 4. HeapSort
void heapBuildWithTime(int index, int a[], int n)
{
    
}

void heapSortWithTime(int a[], int n)
{

}

void heapBuildWithComparison(int index, int a[], int n, unsigned long long &compareCountHeap)
{
   
}

void heapSortWithComparison(int a[], int n, unsigned long long &compareCountHeap)
{
    
}

// 6. QuickSort
int partitionTime(int *arr, int low, int high)
{
    
}

int partitionComparison(int *arr, int low, int high, unsigned long long &countCompareQuick)
{
    
}

void quickSortWithTime(int *arr, int low, int high)
{
   
}

void quickSortWithComparison(int *arr, int low, int high, unsigned long long &countCompareQuick)
{
    
}

// 7.MergeSort
void mergeWithTime(int array[], int const left, int const mid, int const right)
{
    
}

void mergeSortWithTime(int array[], int const begin, int const end)
{
   
}

void mergeWithComparison(int array[], int const left, int const mid, int const right, unsigned long long &count_compare)
{
    
}

void mergeSortWithComparison(int array[], int const begin, int const end, unsigned long long &count_compare)
{
   
}

// 9.RadixSort
int MaxNumber(int a[], int n, unsigned long long &count_compare)
{
    
}

void Count(int arr[], int n, int exp, unsigned long long &count_compare)
{
    
}

void radixSortWithComparison(int a[], int n, unsigned long long &count_compare)
{
    
}

int MaxNumber1(int a[], int n)
{
    
}

void Count1(int arr[], int n, int exp)
{
   
}

void radixSortWithTime(int a[], int n)
{
    
}
