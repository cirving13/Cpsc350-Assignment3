#include <iostream>
#include <string>
#include "EmptyStackException.h"
using namespace std;

template <class T>
class GenStack
{
public:
    //constructors/destructors
  GenStack();
  GenStack(int maxSize);
  ~GenStack();
    //main functions
  void push(T data);
  T pop();
  T topStack();
  void enlarge();
    //supporting function
  bool isFull();
  bool isEmpty();
  int getSize();
    //variables
  int size;
  int top;
private:
  T *myArray;
};

template <class T>
GenStack<T>::GenStack()
{
  myArray = new T[256];
  size = 256;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack()
{
  cout << "deleted" << endl;
  delete myArray;
}

template <class T>
void GenStack<T>::push(T data)
{
  if(isFull()) //if full, double the size of the stack, then push the data
  {
    enlarge();
  }
  myArray[++top] = data; //increases value of top first and then adds data to top
}

template <class T>
void GenStack<T>::enlarge() //doubles the size of the stack to allow for longer code
{
  T* tempArray = new T[2*size];
  for(int i = 0; i < size; ++i) //loop moving the information to the larger stack
  {
    tempArray[i] = myArray[i];
  }
  delete myArray;
  myArray = tempArray;
  delete tempArray;
  size = size * 2;
}

template <class T>
T GenStack<T>::topStack() //looks at the top of the stack
{
  if(isEmpty())
  {
    throw EmptyStackException();
  }
  return myArray[top];
}

template <class T>
T GenStack<T>::pop() //checks if empty and then removes the top value from the stack
{
  if(isEmpty())
  {
    throw EmptyStackException();
  }
  return myArray[top--]; //post operation deincrement so it moves the top down after it removes the value of top
}

template <class T>
bool GenStack<T>::isFull() //checks if full
{
  return (top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty()//checks if empty
{
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize() //getter for the size of the stack
{
  return(top+1);
}
