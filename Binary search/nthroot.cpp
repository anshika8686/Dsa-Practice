
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int nthRoot(int n, int m)
  {
    // Code here
    int low = 1, high = m, mid = -1;
    long long root = 1;
    if (m == 1)
      return m;
    while (low <= high)
    {
      mid = (low + high) / 2;
      root = 1;
      for (int i = 1; i <= n; i++)
      {
        root = root * mid;
        if (root > m)
          break;
      }
      if (root == m)
      {
        return mid;
      }
      else if (root > m)
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return -1;
  }
};
int main()
{
  Solution sol;
  int n = 3, m = 9;
  int root = sol.nthRoot(n, m);
  cout << "The nth root is = " << root << endl;
  return 0;
}
