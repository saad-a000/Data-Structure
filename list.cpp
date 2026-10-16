#include <iostream>
using namespace std;

class List
{
private:
  int *arr;
  int *curr;
  int length;
  int cap;

public:
  List(int size)
  {
    arr = new int[size];
    curr = arr;
    length = 0;
    cap = size;
  }

  void start()
  {
    curr = arr;
  }

  void end()
  {
    curr = arr + length - 1;
  }

  void fill(int val)
  {
    *curr = val;
    curr++;
    length++;
  }

  void insert(int val, int pos)
  {
    start();

    for (int i = length; i > pos; i--)
    {
      *(curr + i) = *(curr + i - 1);
    }
    *(curr + pos - 1) = val;
    length++;
  }

  void remove(int pos)
  {
    start();

    for (int i = pos; i <= length; i++)
    {
      *(curr + i - 1) = *(curr + i);
    }
    length--;
  }

  void update(int val, int pos)
  {
    start();

    for (int i = 1; i <= length; i++)
    {
      if (i == pos)
      {
        *(curr + i - 1) = val;
      }
    }
  }
  void find_length()
  {
    int count = 0;
    start();

    for (int i = 1; i <= length; i++)
    {
      count++;
    }
    cout << "The number of elements int this array are : " << count;
  }

  void find_element(int val)
  {
    start();

    for (int i = 1; i <= length; i++)
    {
      if (*(curr + i - 1) == val)
      {
        cout << "Element exist in this list";
      }
    }
  }

  void copy(List other)
  {
    length = other.length;

    for (int i = 1; i <= length; i++)
    {
      *(arr + i - 1) = *(other.arr + i + 1);
    }
  }
};
int main()
{
  int n;

  cout << "Enter the size eof array : ";
  cin >> n;

  List l1(n);

  l1.fill(5);
  l1.fill(6);
  l1.fill(4);
  l1.fill(2);
  l1.fill(8);

  int pos, val;
  cout<<"Enter the position and value to insert : ";
  cin>> pos, val;

  l1.insert(pos,val);
  cout<<"The updated list is : ";
  

  int index;
  cout<<"Enter the index which ypu want to remove : ";
  cin>>index;

  l1.remove(index);

  int up, ind;

  cout<<"Enter the value you want to update and the index : ";
  cin>> up, ind;

  l1.find_length();

  int find_val;
  cout<<"Enter the element you want to find :  ";
  cin>>find_val;

  l1.find_element(find_val);

  List l2(5);
  l2.copy(l1);


}
