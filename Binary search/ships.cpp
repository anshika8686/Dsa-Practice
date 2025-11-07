
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int shipWithinDays(vector<int> &weights, int days)
  {
    // mid represents the capacity it can takea
    int n = weights.size(), sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += weights[i];
    }
    int low = *max_element(weights.begin(), weights.end()), high = sum, mid, d = 1, total_sum = 0, mini = INT_MAX;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      d = 1, total_sum = 0;
      for (int i = 0; i < n; i++)
      {
        total_sum += weights[i];
        if (total_sum > mid)
        {
          total_sum = weights[i];
          d++;
        }
      }
      if (days >= d)
      {
        mini = min(mini, mid);
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    return mini;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 3, 2, 1};
  int cap = sol.shipWithinDays(nums, 5);
  cout << "The least capacity with which it can shipped is = " << cap << endl;
  return 0;
}