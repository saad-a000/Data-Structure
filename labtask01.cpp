/*#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "enter the size of array : ";
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout << "Enter the " << i + 1 << " element : ";
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        for (int k = j; k < n - 1; k++)
        {
          arr[j] = arr[k + 1];
        }
        n--;
        j--;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i];
  }
}*/

/*#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the size of array : ";
  cin >> n;

  int arr[n];

  cout << "Enter the array : ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int smallest = arr[0];
  int ssmall = arr[0];

  for (int i = 0; i < n; i++)
  {
    if (arr[i] < smallest)
    {
      ssmall = smallest;
      smallest = arr[i];
    }
    else if (arr[i] > smallest && arr[i] < ssmall)
    {
        ssmall = arr[i];
    }
  }
  cout << "the second smallest is : " << ssmall;
}*/

#include <iostream>
using namespace std;

int main()
{
  int n;

  cout << "enter the number of integer :  ";
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout << "Enter the elements : ";
    cin >> arr[i];
  }

  int s = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      int temp = arr[i];
      arr[i] = arr[s];
      arr[s] = temp;
      s++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout<<arr[i]<<" ";
  }
}
