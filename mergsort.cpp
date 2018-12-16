#include <iostream>
using namespace std;

#define Max 1000

//define function
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
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

	mergeSort(arr, 0, count - 1);

	cout << "\nSorted array is \n";
	printArray(arr, count);

	return 0;
}

//functions
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[Max], R[Max];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << endl;
}