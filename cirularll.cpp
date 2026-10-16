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

class Circular
{
public:
  Node *head;
  Node *tail;

  Circular()
  {
    head = tail = NULL;
  }

  void pushback(int value)
  {
    Node *newnode = new Node(value);

    if (head == NULL)
    {
      head = tail = newnode;
      tail->next = head;
    }
    else
    {
      tail->next = newnode;
      tail = newnode;
      tail->next = head;
    }
  }

  void insert(int val, int pos)
  {
    Node *newnode = new Node(val);
    Node *curr = head;

    if (pos == 1)
    {
      newnode->next = head;
      head = newnode;
      tail->next = head;
    }
    else
    {
      for (int i = 1; i < pos - 1; i++)
      {
        curr = curr->next;
      }
      newnode->next = curr->next;
      curr->next = newnode;
    }
  }
  void reverse()
  {
    Node *prev = tail;
    Node *curr = head;
    Node *temp = NULL;

    do
    {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      
    }
    while(curr != head);
    
    head = prev;
  }

  void remove(int pos)
  {
    Node *curr = head;
    if (pos == 1)
    {
      head = head->next;
      tail->next = head;
      delete curr;
    }
    else
    {
      for (int i = 1; i < pos - 1; i++)
      {
        curr = curr->next;
      }
      Node *temp = curr->next;
      curr->next = temp->next;
      delete temp;
    }
  }
  void print()
  {
    Node *curr = head;

    do
    {
      cout << curr->data << " ";
      curr = curr->next;
    } while (curr != head);

    cout << endl;
  }
};

int main()
{
  Circular c1;

  c1.pushback(4);
  c1.pushback(9);
  c1.pushback(2);
  c1.pushback(8);
  c1.pushback(6);

  c1.print();
  c1.insert(5, 1);
  c1.remove(3);
  c1.print();
  c1.reverse();
  c1.print();
}