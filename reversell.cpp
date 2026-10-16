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
    next = NULL;
  }
};

class List
{
public:
  Node *head;
  Node *tail;

  List()
  {
    head = tail = NULL;
  }

  void pushback(int value)
  {
    Node *newNode = new Node(value);

    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void print()
  {
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->data;
      temp = temp->next;
    }
    cout<<endl;
  }

  void reverse()
  {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      head = prev;
    }
  }
};

int main()
{
  List l1;

  l1.pushback(1);
  l1.pushback(2);
  l1.pushback(3);
  l1.print();
  l1.reverse();
  l1.print();
}
