#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node *prev;

  Node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

class Doubly
{
public:
  Node *head;
  Node *tail;
  int length;

  Doubly()
  {
    head = NULL;
    tail = NULL;
    length = 0;
  }

  void pushback(int value)
  {
    Node *newnode = new Node(value);

    if (head == NULL)
    {
      head = tail = newnode;
    }
    else
    {
      tail->next = newnode;
      newnode->prev = tail;
      tail = newnode;
    }
    length++;
  }
  void changepos(int from, int to)
  {
    Node *curr = head;

    for (int i = 1; i < from - 1; i++)
    {
      curr = curr->next;
    }
    Node *temp = curr;    // stores 2
    Node *A = curr->next; // stores 5

    curr = head;
    
    for (int i = 1; i < to - 1; i++)
    {
      curr = curr->next;
    }
    Node *intemp = curr;    // stores 8
    Node *B = intemp->next; // stores 9

    A->next = B->next; // 5 to 6
    B->next->prev = A; // 6 with 5

    Node *C = temp;
    temp->next = intemp->next; // 2 with 9
    intemp->next->prev = temp; // 9 with 2

    intemp->next = A; // 8 with 5
    A->prev = intemp; // 5 with 8

    B->next = intemp;  // 9 to 8
    B->next->prev = B; // 8 to 9
  }

  void reverse()
  {
    Node *curr = tail;

    while (curr != NULL)
    {
      cout << curr->data << " ";
      curr = curr->prev;
    }
  }

  void print()
  {
    Node *curr = head;

    while (curr != NULL)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }
};

int main()
{
  Doubly d1;

  d1.pushback(2);
  d1.pushback(5);
  d1.pushback(8);
  d1.pushback(9);
  d1.pushback(6);

  d1.print();
  d1.changepos(2, 4);
  d1.print();
  d1.reverse();
}
