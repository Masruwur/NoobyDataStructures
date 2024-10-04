#include <iostream>
//#include "QueueArray.h"
#include "QueueLinkedList.h"
using namespace std;



class Stack
{
private:
    Queue* main;
    
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Stack()
    {
        main = new Queue;


        //write your code here. Initialize additional private variables if necessary
    }

    // No capacity required for linked list implementation

    // Stack(int initialCapacity)
    // {   
    //     main = new Queue(initialCapacity);
    //     aux = new Queue(initialCapacity);
    //     //write your code here. Initialize additional private variables if necessary
    // }

    // Destructor
    ~Stack()
    {
        delete main;
    }

    
    // Push an element onto the stack
    void push(int x)
    {   
        main->enqueue(x);

        if(main->length()==1) return;

        for(int i=0;i<main->length()-1;i++){
            main->enqueue(main->dequeue());
        }


        //write your code here.
        //push the element onto the stack
    }

    // Remove and return the top element
    int pop()
    {  

       return main->dequeue();


       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
    }

    // Return the top element without removing it
    int top()
    {  
        return main->peek();
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
    }

    // Return the number of elements in the stack
    int length()
    {   
        return main->length();
        //write your code here. Return the number of elements in the stack
    }

    // Check if the stack is empty
    bool isEmpty()
    {
         return main->isEmpty();
        //write your code here. Return true if the stack is empty, false otherwise
    }

    // Clear the stack
    void clear()
    {
        main->clear();
        //write your code here. Clear the stack.
        
    }
};
