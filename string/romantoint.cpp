#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int romanToInt(string s)
  {
    int ans = 0;
    map<char, int> hashmap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    for (int i = 0; i < s.size() - 1; i++)
    {
      if (hashmap[s[i]] < hashmap[s[i + 1]])
      {
        ans = ans - hashmap[s[i]];
      }
      else
      {
        ans = ans + hashmap[s[i]];
      }
    }
    ans = ans + hashmap[s[s.size() - 1]];
    return ans;
  }
};
int main()
{
  Solution sol;
  string s = "MCMXCIV";
  int ans = sol.romanToInt(s);
  cout << "The interger value of this roman numeral is: " << ans << endl;
  return 0;
}