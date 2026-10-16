#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

class Queue
{
  Node *front;
  Node *rear;

public:
  Queue()
  {
    front = rear = NULL;
  }

  void enqueue(int val)
  {
    Node *newnode = new Node(val);

    if (front == NULL)
    {
      front = rear = newnode;
    }
    else
    {
      rear->next = newnode;
      rear = newnode;
    }
  }
  bool isEmpty()
  {
    if (front == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void dequeue()
  {
    if (isEmpty())
    {
      cout << "Queue is empty .";
      return;
    }

    Node *curr = front;

    front = front->next;
    delete curr;

    if (front == NULL)
    {
      rear = NULL;
    }
  }

  void print_queue()
  {
    Node *curr = front;

    while (curr!= NULL)
    {
      cout<<curr->data<<" ";
      curr = curr->next;
    }

  }
};
int main()
{
  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.dequeue();
  q.dequeue();

  q.print_queue();
}