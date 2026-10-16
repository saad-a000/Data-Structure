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

  bool detect_cycle()
  {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow)
      {
          return true;
      }
    }
    return false;
  }
};

int main()
{
  List l1;
  l1.pushback(1);
  l1.pushback(2);
  l1.pushback(3);
  l1.pushback(4);
  l1.pushback(5);
  l1.pushback(6);

  Node *temp = l1.head;

  while (temp->data != 3)
  {
    temp = temp->next;
  }

  l1.tail->next = temp;

  cout<<l1.detect_cycle();
}