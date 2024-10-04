#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

class Queue
{
private:
    Node *peekNode; // Points to the front of the queue
    int currentSize;

public:
    // Constructor
    Queue()
    {
        peekNode = nullptr;
        currentSize = 0;
    }

    // Enqueue an element onto the queueu
    void enqueue(int x){
      
      if(peekNode==nullptr){
        peekNode = new Node(x);
        currentSize++;
        return;
      }

      Node* insertion = new Node(x);
      Node* temp = peekNode;
      while(temp->next) temp = temp->next;

      temp->next = insertion;
      currentSize++;

       //can be O(1) with a tail pointer

       // write your code here. Create a new node with the value x and enqueue it onto the queue
       // update the peekNode and currentSize


    }

    // Remove and return the peek element
    int dequeue(){

        if(peekNode==nullptr){
            cout<<"empty queue"<<endl;
            return INT32_MIN;
        }

        Node* temp = peekNode;
        int res = peekNode->data;

        peekNode = peekNode->next;
        currentSize--;
        
        delete temp;
        return res;
    
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // dequeue the peek element and return it
        // update the peekNode and currentSize
        // delete the node that was dequeued
    }

    // Return the peek element without removing it
    int peek(){
        if(peekNode==nullptr){
             cout<<"empty queue"<<endl;
             return INT32_MIN;
        }

        return peekNode->data;
    
        // write your code here. Check if the queueu is empty and return -1 if it is.
        // return the peek element
    }

    // Return the number of elements in the queueu
    int length()
    {   
        return currentSize;
        // write your code here. Return the number of elements in the queueu
    }

    // Check if the queueu is empty
    bool isEmpty()
    {   
        return currentSize==0;
        // write your code here. Return true if the queueu is empty, false otherwise
    }

    // Clear the queueu
    void clear()
    {
        while (!isEmpty())
        {
            dequeue(); // Continuously dequeue elements until the queueu is empty
        }
    }

    // Destructor
    ~Queue()
    {
        clear();
    }
};
