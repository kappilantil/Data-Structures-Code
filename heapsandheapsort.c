//Given an array, build a heap and sort it!
//The heap is built using the bottom-up method
//The heap is sorted using the top-down method
//The heap is sorted in ascending order
//The heap is sorted in place
//The heap is sorted in place using the top-down method

#include "stdio.h"
#include "stdlib.h"




//Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to heapify the array
void heapify(int arr[], int n, int i)
{
    int largest = i; //Initialize largest as root
    int l = 2*i + 1; //left = 2*i + 1
    int r = 2*i + 2; //right = 2*i + 2

    //If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    //If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    //If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        //Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

//Function to build a heap from an array
void buildHeap(int arr[], int n)
{
    //Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    //Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

//Function to sort the array using heap sort
void heapSort(int arr[], int n)
{
    //Build heap (rearrange array)
    buildHeap(arr, n);

    //One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        //Move current root to end
        swap(&arr[0], &arr[i]);

        //call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//Function to print the array
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("
");
}

//Main function
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is ");
    printArray(arr, n);
}


