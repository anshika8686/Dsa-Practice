#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int floorSqrt(int n)
  {
    int low = 1, high = n - 1, maxi = 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int square = (mid * mid);
      if (square == n)
      { // perfect square
        return mid;
      }
      if (square > n)
      {
        high = mid - 1;
      }
      else
      {
        maxi = max(maxi, mid);
        low = mid + 1;
      }
    }
    return maxi;
  }
};
int main()
{
  Solution sol;
  int n = 11;
  int sqrt = sol.floorSqrt(n);
  cout << "The square root is = " << sqrt << endl;
  return 0;
}
