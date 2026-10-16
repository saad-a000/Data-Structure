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

public:
  void push_front(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }
  void pop_front()
  {
    if (head == NULL)
    {
      cout << "Linked list is empty";
    }
    else
    {
      Node *temp = head;
      head = head->next;
      temp->next = NULL;
      delete temp;
    }
  }

  void push_back(int valu)
  {
    Node *newnode = new Node(valu);
    if (head == NULL)
    {
      head = tail = newnode;
    }
    else
    {
      tail->next = newnode;
      tail = newnode;
    }
  }

  void pop_back()
  {
    Node *temp = head;

    while (temp->next != tail)
    {
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp; 

  }

  void printll()
  {
    Node *temp = head;

    while (temp != NULL)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << "Null" << endl;
  }
};

int main()
{

  List l1;

  l1.push_front(1);
  l1.push_front(2);
  l1.push_front(3);
  l1.printll();
  l1.pop_front();
  l1.printll();
}
