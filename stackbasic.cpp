/*#include <iostream>
#include <vector>
using namespace std;    // vector

class Stack
{
  vector<int> v;

public:
  void push(int value)
  {
    v.push_back(value);
  }
  void pop()
  {
    v.pop_back();
  }
  int top()
  {
    return v[v.size() - 1];
  }
  bool empty()
  {
    return v.size() == 0;
  }
};

int main()
{
  Stack s1;

  s1.push(10);
  s1.push(20);
  s1.push(30);

  while (!s1.empty()) // condition of non empty stack, ar stack non empty ha tou implement kro
  {
    cout<<s1.top()<<" ";
    s1.pop();
  }
}*/

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

class Stack
{
public:
  Node *head = NULL;

  void push(int value)
  {
    Node *newnode = new Node(value);

    if (head == NULL)
    {
      head = newnode;
    }
    else
    {
      newnode->next = head;
      head = newnode;
    }
  }

  void pop()
  {
    if (head == NULL)
    {
      cout << "stack is empty."; // Stack is empty
    }
    else
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
  int top()
  {
    if (head == NULL)
    {
      cout << "Stack is empty.";
      return -1; // or throw an exception
    }
    else
    {
      return head->data;
    }
  }
  void display()
  {
    if (head == NULL)
    {
      cout << "Stack is empty." << endl;
    }
    else
    {
      Node *temp = head;

      while (temp != NULL)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }

      cout << endl;
    }
  }
};

int main()
{
  Stack s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.display();
}