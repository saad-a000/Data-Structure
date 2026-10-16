#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
  vector<int> price = {100, 80, 60, 70, 60, 75, 85};

  vector<int> ans;
  stack<int> s;

  for (int i = 0; i < s.size(); i++)
  {
    while (s.size() > 0 && price[s.top() <= price[i]])         // price[s.top()] it means the price at the top index
    {
      s.pop();
    }
    if (s.empty())
    {
      ans[i] = i+1; 
    }
    else{
      ans[i] = i - s.top();
    }
  }
}