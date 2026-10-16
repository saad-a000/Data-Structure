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
  int middle()
  {
    Node *temp = head;

    int count = 0;

    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
    int size = (count / 2) + 1;

    temp = head;

    for (int i = 1; i < size; i++)
    {
      temp = temp->next;
    }
    return temp->data;
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

  cout<<l1.middle();
}

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
  int middle()
  {
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }

    Node *fast = head;
    Node *slow = head;

    if (count % 2 == 0)
    {

      while (fast != NULL)
      {
        fast = fast->next->next;
        slow = slow->next;
      }
       return slow->data;
    }

    else
    {
      while (fast->next != NULL)
      {
        fast = fast->next->next;
        slow = slow->next;
      }
      return slow->data;
    }
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

  cout << l1.middle();
}
