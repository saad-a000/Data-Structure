/*#include <iostream>
using namespace std;

class Stack
{
  int *arr;
  int cap;
  int top;

public:
  Stack(int s)
  {
    arr = new int[s];
    cap = s;
    top = -1;
  }

  ~Stack()
  {
    delete[] arr;
  }

  bool isEmpty()
  {
    if (top == -1)
      return true;
    else
      return false;
  }

  bool isFull()
  {
    if (cap == top + 1)
      return true;
    else
      return false;
  }

  int pop()
  {
    if (isEmpty())
    {
      cout << "underflow";
      return -1;
    }

    int val = arr[top];
    top--;
    return val;
  }

  int peek()
  {
    return arr[top];
  }

  void push(int x)
  {
    if (x == 'C')
    {
      pop();
    }
    else if (x == 'D')
    {
      int z = arr[top] * 2;
      top++;
      arr[top] = z;
    }
    else if (x == '+')
    {
      int f = arr[top] + arr[top - 1];
      top++;
      arr[top] = f;
    }
    else
    {
      top++;
      arr[top] = x;
    }
  }

  void print()
  {
    for (int i = 0; i <= top; i++)
    {
      cout << arr[i] << " ";
    }
  }
};

int main()
{
  Stack s(5);

  s.push(1);
  //s.push(5);
  s.push('C');
  //s.push('D');
  //s.push('+');

  s.print();
}*/

#include <iostream>
#include <string>
using namespace std;

class Stack
{
  string *arr;
  int cap;
  int top;

public:
  Stack(int s)
  {
    arr = new string[s];
    cap = s;
    top = -1;
  }

  ~Stack()
  {
    delete[] arr;
  }

  bool isEmpty()
  {
    if (top == -1)
      return true;
    else
      return false;
  }

  bool isFull()
  {
    if (cap == top + 1)
      return true;
    else
      return false;
  }

  string pop()
  {
    if (isEmpty())
    {
      cout << "underflow";
      return "";
    }

    string val = arr[top];
    top--;
    return val;
  }

  string peek()
  {
    return arr[top];
  }

  void push(string val)
  {
    if (isFull())
      return;

    top++;
    arr[top] = val;
  }
  void clear()
  {
    top = -1;
  }
};

int main()
{
  Stack action(100);
  Stack redo(100);

  string choice;

  while (true)
  { cout<<endl;
    cout << "--------Options--------";
    cout << "\nCar Control Menu\n";
    cout << "1. Accelerate\n";
    cout << "2. Brake\n";
    cout << "3. Decelerate\n";
    cout << "4. Turn Left\n";
    cout << "5. Turn Right\n";
    cout << "Z. Undo\n";
    cout << "Y. Redo\n";
    cout << "Q. Quit\n";
    cout << "Choice: ";

    cin >> choice;

    if (choice == "1")
    {
      action.push("Accelerate");
      redo.clear();
      cout << "accelerate." << endl;
    }
    else if (choice == "2")
    {
      action.push("Brake");
      redo.clear();
      cout << "brake applied";
    }
    else if (choice == "3")
    {
      action.push("decleerate");
      redo.clear();
      cout << "decleerate";
    }
    else if (choice == "4")
    {
      action.push("Turn left");
      redo.clear();
      cout << "Turn left";
    }
    else if (choice == "5")
    {
      action.push("Turn Right");
      redo.clear();
      cout << "Turn Right";
    }
    else if (choice == "Y")
    {
      if (action.isEmpty())
        cout << "Nothing to undo\n";
      else
      {
        string last = action.peek();
        redo.push(last);
      }
    }
    else if (choice == "Z")
    {
      if (action.isEmpty())
        cout << "Nothing to undo\n";
      else
      {
        string latest = action.pop();
        redo.push(latest);
        cout << "Undo : " << latest << endl;
      }
    }
    else if (choice == "Q")
    {
      return 0;
    }
    else
    {
      cout << "Invalid choice. " << endl;
    }
  }
}
