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

class List
{
public:
  Node *head;
  Node *tail;
  int length;

  List()
  {
    head = NULL;
    length = 0;
  }

  void fill(int val)
  {
    Node *newnode = new Node(val);
    if (head == NULL)
    {
      head = newnode;
    }
    else
    {
      newnode->next = head; // n would hold the address of head in its next
      head = newnode;
    }
    length++;
  }
  void push_back(int val)
  {

    Node *newnode = new Node(val);

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

  void print()
  {
    Node *curr = head;

    while (curr != NULL)
    {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << endl;
  }

  void reversell()
  {
    Node *prev = NULL;
    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL)
    {
      temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
      head = prev;
    }
  }
  void changePos(int from, int to)
  {
    Node *curr = head;

    for (int i = 1; i < from - 1; i++)
    {
      curr = curr->next;
    }

    Node *prevA = curr;    // hold address of 6
    Node *A = prevA->next; // holds address of 7

    curr = head;

    for (int i = 1; i < to - 1; i++)
    {
      curr = curr->next;
    }

    Node *prevB = curr;    // holds address of 4
    Node *B = prevB->next; // holds address of 9

    prevA->next = B; // points to 9
    prevB->next = A; // points to 7

    Node *temp = A->next; // points to 4
    A->next = B->next;    // 8
    B->next = temp;       //
  }

  void remove_duplicates()
  {
    Node *curr = head;

    while (curr != NULL)
    {
      Node *temp = curr->next;

      while (temp != NULL)
      {
        if (temp->val == curr->val)
        {
          curr->next = temp->next;

          Node *in_temp = temp;
          temp = temp->next;
          delete in_temp;
          length--;
        }
        else
        {
          temp = temp->next;
        }
      }
      curr = curr->next;
    }
  }
  void remove(int index)
  {
    Node *curr = head;

    if (index == 1)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
    else
    {

      for (int i = 1; i < index - 1; i++)
      {
        curr = curr->next;
      }
      Node *temp = curr->next;
      curr->next = temp->next;
      delete temp;
    }
  }
};

int main()
{
  List l1;
  l1.push_back(6);
  l1.push_back(7);
  l1.push_back(4);
  l1.push_back(9);
  l1.push_back(8);

  l1.print();
  // l1.changePos(2, 4);
  // l1.print();

  l1.reversell();
  l1.print();

  // l1.remove_duplicates();
  // l1.print();
}