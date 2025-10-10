#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    if (s.size() != t.size())
      return false;

    map<char, char> charmap1;
    map<char, char> charmap2;

    for (int i = 0; i < s.size(); i++)
    {
      char ch1 = s[i];
      char ch2 = t[i];

      if (charmap1.find(ch1) != charmap1.end())
      {
        if (charmap1[ch1] != ch2)
          return false;
      }
      else
      {
        charmap1[ch1] = ch2;
      }

      if (charmap2.find(ch2) != charmap2.end())
      {
        if (charmap2[ch2] != ch1)
          return false;
      }
      else
      {
        charmap2[ch2] = ch1;
      }
    }
    return true;
  }
};
int main()
{
  Solution sol;
  string s = "egg";
  string t = "add";
  bool ans = sol.isIsomorphic(s, t);
  cout << boolalpha << ans << endl; //  prints "true" or "false"
  return 0;
}
