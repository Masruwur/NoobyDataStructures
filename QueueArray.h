#include <iostream>
using namespace std;

class Queue
{
private:
    int *array;
    int start;
    int end;
    int capacity;
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Queue()
    {
        array = new int[1];
        capacity=1;
        start = end = -1;
        //write your code here. Initialize additional private variables if necessary
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity];
        capacity = initialCapacity;
        start = end = -1;
         // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
    }

    //copy

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    { 
        int *newArray = new int[newCapacity];  // Allocate new array

        if(isEmpty()){
            delete[] array;
            array = newArray;
            capacity = newCapacity;

            return;
        }

        for(int i=(start%capacity);i<capacity;i++) newArray[i-start]=array[i];

        for(int i=0;i<=(end%capacity);i++) newArray[capacity-start+i] = array[i];


        //write your code here. Copy the elements from the old array to the new array

        delete[] array; // Free old memory

        array = newArray;
        capacity = newCapacity;

        int size = end-start+1;
        start = 0;
        end = size-1;

        //write your code here. Update the capacity and array pointers
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {  
       if(start==-1 && end==-1){
          array[0]=x;
          start=end=0;  
          return;
        }

       if((end-start+1)==capacity) this->resize(2*capacity);

       end++;
       array[end%capacity] = x; 
        

        //write your code here. Check if the array is full and resize if necessary.
    }

    // Remove and return the peek element
    int dequeue()
    {   if(start==-1 && end ==-1){
             cout<<"empty queue"<<endl;
             return INT32_MIN;
        }

        if(start%capacity == end%capacity){
             int res = array[start%capacity];
             start = end = -1;

             return res;
        }

        int res = array[start%capacity];
        start++;


        return res;

        
       //write your code here. Check if the stack is empty and return -1 if it is.
       //remove the peek element and return it
       //resize the array if necessary
    }

    // Return the peek element without removing it
    int peek()
    {   if(isEmpty()){
           cout<<"empty queue"<<endl;
           return INT32_MIN;
        }

        return array[start%capacity];
        
        //write your code here. Check if the queue is empty and return -1 if it is.
        //return the peek element
    }

    // Return the number of elements in the queue
    int length()
    {   
        int size = end-start+1;

        return isEmpty() ? 0:size;
        
        
        //write your code here. Return the number of elements in the queue
    }

    // Check if the queue is empty
    bool isEmpty()
    {   
        return (start==-1 && end==-1);

        //write your code here. Return true if the queue is empty, false otherwise
    }

    // Clear the queue
    void clear()
    {   
        delete[] array;

        array = new int[1];
        capacity=1;
        end=start=-1;


        //write your code here. Clear the queue. resize the array to 1

    }
};
