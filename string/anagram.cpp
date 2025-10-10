#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    int n1 = s.size();
    int n2 = t.size();
    map<char, int> hashmap;
    if (n1 == n2)
    {
      for (int i = 0; i < n1; i++)
      {
        hashmap[s[i]]++;
      }
      for (int j = 0; j < n1; j++)
      {
        if (hashmap.find(t[j]) == hashmap.end())
        {
          return false;
        }
        hashmap[t[j]]--;
        if (hashmap[t[j]] < 0)
          return false;
      }
      return true;
    }
    return false;
  }
};
int main()
{
  Solution sol;
  string s = "anagram";
  string t = "nagaram";
  bool ans = sol.isAnagram(s, t);
  cout << "isAnagaram" << boolalpha << ans << endl; //  prints "true" or "false"
  return 0;
}