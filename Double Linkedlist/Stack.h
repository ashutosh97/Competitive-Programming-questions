
#ifndef INTSTACK_H
 #define INTSTACK_H
#include <iostream>;
using namespace std;

 class IntStack
 {
 private:
	 int *stackArray; // Pointer to the stack array
	 int stackSize; // The stack size
	  // Indicates the top of the stack
	
 public:
	 int top;
	 // Constructor
		 IntStack(int size =10)
		 {
			  stackArray = new int[7];
			  stackSize = size;
			  top = -1;
			 
		 }
		 
	
		 
	
		 // Destructor
		 ~IntStack()
		 {
			  delete[] stackArray;
			 
		 }
	
		 // Stack operations
		 void push(int num)
		 {
			  if (isFull())
				  {
				  cout << "The stack is full.\n";
				  }
			  else
				  {
				  top++;
				  stackArray[top] = num;
				  }
			 
		 }
	 int pop()

	 {
		 int num;
		  if (isEmpty())
			  {
			 cout << "The stack is empty.\n";
			  }
		 else
			  {
			  num = stackArray[top];
			  top--;
			  }
		  return num;
		 
	 }

	 bool isFull() const
	 {
		  bool status;
		 
			  if (top == stackSize -1)
			  status = true;
		  else
			  status = false;
		 
			  return status;
		 
	 }
	 bool isEmpty() const
	 {
		  bool status;
		 
			  if (top == -1)
			  status = true;
		  else
		  status = false;
		 
			  return status;
		  }
	 };
 #endif

