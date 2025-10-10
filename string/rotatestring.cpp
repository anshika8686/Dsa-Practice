#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    int n = s.size();
    for (int i = 0; i <= n - 1; i++)
    {
      string strcopy = s;
      reverse(strcopy.begin(), strcopy.begin() + i);
      reverse(strcopy.begin() + i, strcopy.end());
      reverse(strcopy.begin(), strcopy.end());
      if (strcopy == goal)
      {
        return true;
      }
    }
    return false;
  }
  //-----------------------------------------tc=O(2n)----------------------------------------
  bool rotateStringoptimal(string s, string goal)
  {
    string doubled = s + s;
    if (s.size() != goal.size())
      return false;
    if (doubled.find(goal) != string::npos)
    { // string::npos means not found
      return true;
    }
    return false;
  }
};
int main()
{
  Solution sol;
  string s = "abcde";
  string goal = "eabcd";
  bool ans = sol.rotateString(s, goal);
  cout << boolalpha << ans << endl; //  prints "true" or "false"
  return 0;
}
// tc=O(n2) sc=o(n)