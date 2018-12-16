
#include <iostream>
using namespace std; 
  
#define MAX 1000 
  
class Queue 
{ 
    int first;
    int last;
public: 
    int a[MAX];    //Maximum size of Stack 
  
    Queue()  { first=0;last=-1; } 
    bool add(int x); 
    int del(); 
    bool isEmpty(); 
}; 
  
bool Queue::add(int x)
{
    if(last>=(MAX-1))
    {
        cout << "list por shode!"; 
        return false; 
    }
    else
    {
    	last++;
        a[last]=x;
    }
}

int Queue::del()
{
    if(isEmpty())
    {
        cout << "list khali"; 
        return 0;
    }
    else
    {
        return a[first++];
    }
}
  
bool Queue::isEmpty() 
{ 
    return (first > last); 
} 
  
int main() 
{ 
    struct Queue s; 
    s.add(10); 
    s.add(20); 
    s.add(30); 
    cout<<s.del() << " bardashte shod\n"; 
  
    return 0; 
} 
