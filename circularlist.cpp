
#include <iostream>
using namespace std; 
  
#define MAX 1000 
  
class Queue 
{ 
    int payan, shoro;
    int size; 
    int *arr;
public: 
    Queue(int s)  {
       shoro = payan = -1; 
       size = s; 
       arr = new int[s]; 
       } 
    void add(int x); 
    int del();
    void sort();
    void display();
}; 


void Queue::add(int value) 
{ 
    if ((shoro == 0 && payan == size-1) || 
            (payan == (shoro-1)%(size-1))) 
    { 
        cout<<"\nsaf por hast"; 
        return; 
    } 
  
    else if (shoro == -1) 
    { 
        shoro = payan = 0; 
        arr[payan] = value; 
    } 
  
    else if (payan == size-1 && shoro != 0) 
    { 
        payan = 0; 
        arr[payan] = value; 
    } 
  
    else
    { 
        payan++; 
        arr[payan] = value; 
    } 
} 
  
int Queue::del() 
{ 
    if (shoro == -1) 
    { 
        cout<<"\nlist khali"; 
        return INT_MIN; 
    } 
  
    int data = arr[shoro]; 
    arr[shoro] = -1; 
    if (shoro == payan) 
    { 
        shoro = -1; 
        payan = -1; 
    } 
    else if (shoro == size-1) 
        shoro = 0; 
    else
        shoro++; 
  
    return data; 
} 

void Queue::sort() 
{ 
    if (shoro == -1) 
        return; 
 
    int temp;
    if (payan >= shoro) 
    { 
        for (int i=0; i < size; i++)
        {
            for (int j=0; j < size-i-1; j++)
            {
                if( arr[j]>arr[j+1] )
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    } 
     
} 

void Queue::display() 
{ 
    if (shoro == -1) 
    { 
        cout<<"\nlist khali"; 
        return; 
    } 

    cout<<"\nlist: "; 
    if (payan >= shoro) 
    { 
        for (int i = shoro; i <= payan; i++) 
            cout<<arr[i]<<", "; 
    } 
    else
    { 
        for (int i = shoro; i < size; i++) 
            cout<<arr[i]; 
  
        for (int i = 0; i <= payan; i++) 
            cout<<arr[i]; 
    } 
} 
  
int main() 
{ 
    int arr[] = {10, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    Queue q(n);
    for(int i=0;i<n;i++)
    {
        q.add(arr[i]);
    }

    q.display();
    q.sort();
    q.display();
  
    return 0; 
} 
