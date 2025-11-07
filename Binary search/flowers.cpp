#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minDays(vector<int> &bloomDay, int m, int k)
  {
    int n = bloomDay.size();
    int mini = *min_element(bloomDay.begin(), bloomDay.end());
    int maxi = *max_element(bloomDay.begin(), bloomDay.end());
    int low = mini, high = maxi, mid, flowers = 0, bouquet = 0, mini_days = INT_MAX;
    if ((long long)m * k > n)
      return -1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      bouquet = 0, flowers = 0;
      for (int i = 0; i < n; i++)
      {
        if (bloomDay[i] <= mid)
        {
          flowers++;
          if (flowers == k)
          {
            bouquet++;
            flowers = 0;
          }
        }
        else
        {
          flowers = 0; // if sequence breaks, starts refresh
        }
      }
      if (bouquet >= m)
      {
        mini_days = min(mini_days, mid);
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return mini_days;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {7, 7, 7, 7, 12, 7, 7};
  int m = 3, k = 2;
  int min_days = sol.minDays(nums, m, k);
  cout << "The minimum days is = " << min_days << endl;
  return 0;
}
