#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = NULL;
  }
};
class Queue
{
  Node *head;
  Node *tail;

public:
  Queue()
  {
    head = tail = NULL;
  }

  void push(int dat)
  {
    Node *newnode = new Node(dat);

    if (empty())
    {
      head = tail = newnode;
    }
    else
    {
      tail->next = newnode;
      tail = newnode;
    }
  }

  void pop()
  {
    if (empty())
    {
      cout << "ll is empty,";
      return;
    }
    else
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  int front()
  {
    return head->data;
  }
};

int main()
{
  Queue q;

  q.push(1);
  q.push(2);

}