#include <iostream>
using namespace std;

class Stack
{
  int *arr;
  int cap;
  int top;

public:
  Stack(int s)
  {
    arr = new int[s];
    top = -1;
  }
  ~Stack()
  {
    delete[] arr;
  }

  bool isEmpty()
  {
    if (top == -1)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool isFull()
  {
    if (cap == (top + 1))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  void push(int x)
  {
    if (isFull())
    {
      cout << "Overflow";
      return;
    }
    top++;
    arr[top] = x;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Underflow.";
      return -1;
    }
    int val = arr[top];
    top--;
    return val;
  }
};

class MyQueue
{

  int front = 0;
  int rear = -1;

public:
  Stack s1, s2;

  while (!s1.isEmpty())
  {
    int val = s1.pop();
    s2.push(val);
  }
  void enqueue(int val)
};
