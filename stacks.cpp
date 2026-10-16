
#include <iostream>
using namespace std;

class Node
{
public:
  int val;
  Node *next;

  Node(int v)
  {
    val = v;
    next = NULL;
  }
};

class Stack
{
  Node *top;

public:
  Stack()
  {
    top = NULL;
  }

  void push(int val)
  {
    Node *newnode = new Node(val);

    newnode->next = top;
    top = newnode;
  }

  bool isEmpty()
  {
    if (top == NULL)
    {
      return true;
    }

    return false;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return -1;
    }

    int val = top->val;

    Node *curr = top;
    top = top->next;

    delete curr;

    return val;
  }

  void peek()
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return;
    }

    cout << top->val << endl;
  }
};

int main()
{
  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);

  s.peek();

  cout << s.pop() << endl;

  s.peek();
}

