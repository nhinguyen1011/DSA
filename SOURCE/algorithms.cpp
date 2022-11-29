#include <iostream>
#include <queue>
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
    bool isHeap = false;
    int l, k = index;

    while (!isHeap && (2 * k + 1) < n)
    {
        l = 2 * k + 1;

        if (l < n - 1)
            if (a[l] < a[l + 1])
                l = l + 1;

        if (a[k] > a[l])
            isHeap = true;
        else
        {
            swap(a[k], a[l]);
            k = l;
        }
    }
}

void heapSortWithTime(int a[], int n)
{
    int pos = (n - 1) / 2;
    while (pos >= 0)
    {
        heapBuildWithTime(pos, a, n);
        pos = pos - 1;
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        n = n - 1;
        heapBuildWithTime(0, a, n);
    }
}

void heapBuildWithComparison(int index, int a[], int n, unsigned long long &compareCountHeap)
{
    bool isHeap = false;
    int l, k = index;

    while ((++compareCountHeap && !isHeap) && (++compareCountHeap && (2 * k + 1) < n))
    {

        l = 2 * k + 1;

        if (++compareCountHeap && l < n - 1)
        {
            if (++compareCountHeap && a[l] < a[l + 1])
            {
                l = l + 1;
            }
        }

        if (++compareCountHeap && a[k] > a[l])
        {
            isHeap = true;
        }
        else
        {
            swap(a[k], a[l]);
            k = l;
        }
    }
}

void heapSortWithComparison(int a[], int n, unsigned long long &compareCountHeap)
{
    int pos = (n - 1) / 2;
    while (++compareCountHeap && pos >= 0)
    {
        heapBuildWithComparison(pos, a, n, compareCountHeap);
        pos = pos - 1;
    }

    for (int i = n - 1; ++compareCountHeap && i > 0; i--)
    {
        swap(a[0], a[i]);
        n = n - 1;
        heapBuildWithComparison(0, a, n, compareCountHeap);
    }
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

void radixSortWithComparison(int a[], int n, unsigned long long &count_compare)
{
    const int radix = 10;
	int digits = 10;
	queue<long> queues[radix];
	
	for(int i = 0, factor = 1; ++count_compare && i < digits; factor *= radix, i++)
	{
		for(int j = 0;++count_compare && j < n; j++)
			queues[((a[j]/factor)%radix)].push(a[j]);
			
		int k = 0;
		
		for(int j = 0;++count_compare && j < radix; j++)
		{
			while(++count_compare && !queues[j].empty())
			{
				a[k] = queues[j].front();
				queues[j].pop();
				k++;
			}
		}
	}
}


void radixSortWithTime(int a[], int n)
{
    const int radix = 10;
	int digits = 10;
	queue<long> queues[radix];
	
	for(int i = 0, factor = 1; i < digits; factor *= radix, i++)
	{
		for(int j = 0; j < n; j++)
			queues[((a[j]/factor)%radix)].push(a[j]);
			
		int k = 0;
		
		for(int j = 0; j < radix; j++)
		{
			while(!queues[j].empty())
			{
				a[k] = queues[j].front();
				queues[j].pop();
				k++;
			}
		}
	}
}
