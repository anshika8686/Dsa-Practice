
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int beautySum(string s)
  {
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    { // O(N)
      vector<int> freq(26, 0);
      for (int j = i; j < s.size(); j++)
      { // O
        freq[s[j] - 'a']++;
        int maxi = INT_MIN, mini = INT_MAX;
        for (auto &it : freq)
        {
          if (it > 0)
          {
            maxi = max(maxi, it);
            mini = min(mini, it);
          }
        }
        int beauty = maxi - mini;
        count += beauty;
      }
    }
    return count;
  }
};
int main()
{
  Solution sol;
  string s = "aabac";
  int ans = sol.beautySum(s);
  cout << "Total Count:" << ans << endl; //  prints "true" or "false"
  return 0;
}