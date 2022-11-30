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
   int j, min;
    for (int i = 0; ++count_compare && i < n; i++)
    {
        min = i;
        for (j = i + 1; ++count_compare && j < n; j++)
            if (++count_compare && a[j] < a[min])
            {
                swap(a[min], a[j]);
            }
    }
}

void selectionSortWithTime(int a[], int n)
{
    int j, min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
            {
                swap(a[i], a[j]);
            }
    }
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

// 5. QuickSort
int partitionTime(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionComparison(int *arr, int low, int high, unsigned long long &countCompareQuick)
{
    int pivot = arr[high];
	
    int i = (low - 1);
    for (int j = low; ++countCompareQuick && j <= high - 1; j++) {
        
        if (++countCompareQuick && arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortWithTime(int *arr, int low, int high)
{
    if (low < high) {

        int pi = partitionTime(arr, low, high);
	    
        quickSortWithTime(arr, low, pi - 1);
        quickSortWithTime(arr, pi + 1, high);
    }
}

void quickSortWithComparison(int *arr, int low, int high, unsigned long long &countCompareQuick)
{
        if (++countCompareQuick && low < high) {

        int pi = partitionComparison(arr, low, high, countCampareQuick);
	    
        quickSortWithComparison(arr, low, pi - 1, countCampareQuick);
        quickSortWithComparison(arr, pi + 1, high, countCampareQuick);
}

// 6.MergeSort
void mergeWithTime(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortWithTime(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithTime(array, begin, mid);
    mergeSortWithTime(array, mid + 1, end);
    mergeWithTime(array, begin, mid, end);
}

void mergeWithComparison(int array[], int const left, int const mid, int const right, unsigned long long &count_compare)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; ++count_compare && i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; ++count_compare && j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (++count_compare && indexOfSubArrayOne < subArrayOne && ++count_compare && indexOfSubArrayTwo < subArrayTwo)
    {
        if (++count_compare && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (++count_compare && indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (++count_compare && indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSortWithComparison(int array[], int const begin, int const end, unsigned long long &count_compare)
{
    if (++count_compare && begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSortWithComparison(array, begin, mid, count_compare);
    mergeSortWithComparison(array, mid + 1, end, count_compare);
    mergeWithComparison(array, begin, mid, end, count_compare);
}
// 7.RadixSort

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
