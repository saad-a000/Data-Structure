#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int value)
  {
    data = value;
    next = prev = NULL;
  }
};

class Doubly
{
  Node *head;
  Node *tail;

public:
  Doubly()
  {
    head = tail = NULL;

    void pushfront(int value)
    {
      Node *newnode = new Node(value);
      if (head == NULL)
      {
        head = tail = newnode;
      }
      else
      {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
      }
    }

    void print_dl()
    {
      Node *temp = head;

      if (temp != NULL)
      {
        cout << temp->data;

        temp = temp->next;
      }
    }
  }
};

int main()
{
  Doubly d1;
  
}
