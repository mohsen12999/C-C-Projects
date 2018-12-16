/* C++ program for QuickSort */

#include "stdafx.h"
#include <iostream>
using namespace std;

#define Max 1000

//define function
void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);

//program
int main()
{

	int arr[Max];

	int count;
	cout << "Please Enter Numbers count: ";
	cin >> count;

	for (int i = 0; i < count; i++) {
		cout << "Please Enter Number "<<i+1<<": ";
		cin >> arr[i];
	}
	
	cout<<"Given array is \n";
	printArray(arr, count);

	quickSort(arr, 0, count - 1);

	cout << "\nSorted array is \n";
	printArray(arr, count);

	getchar();
	getchar();
	return 0;
}

//functions
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1);  

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << endl;
}