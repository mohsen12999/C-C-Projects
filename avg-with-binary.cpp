#include <iostream> 
using namespace std; 
  
double avgRec(int a[], int i, int n) 
{ 
    if (i == n-1) 
        return a[i]; 
  
    if (i == 0) 
        return ((a[i] + avgRec(a, i+1, n))/n); 
  
    return (a[i] + avgRec(a, i+1, n)); 
} 
  
double average(int a[], int n) 
{ 
     return avgRec(a, 0, n); 
} 
  
int main() 
{ 
    int arr[] = {10, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << average(arr, n) << endl; 
    return 0; 
} 