
#include <iostream>
using namespace std; 
  
#define MAX 1000 
  
class Stack 
{ 
    int top; 
public: 
    int a[MAX];    //Maximum size of Stack 
  
    Stack()  { top = -1; } 
    bool push(int x); 
    int pop(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX-1)) 
    { 
        cout << "Stack por shode!"; 
        return false; 
    } 
    else
    { 
    	top++;
        a[top] = x; 
        cout<<x <<" dakhel stack rikhte shod.\n"; 
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) 
    { 
        cout << "Stack khali"; 
        return 0; 
    } 
    else
    { 
        int x = a[top]; 
        top--;
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
  
int main() 
{ 
    struct Stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout<<s.pop() << " bardashte shod\n"; 
  
    return 0; 
} 
