#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    int n = nums.size();
    int maxi = *max_element(nums.begin(), nums.end());
    int low = 1, high = maxi;
    int mini = INT_MAX;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      int total = 0;

      // compute total sum of ceil(nums[i] / mid)
      for (int i = 0; i < n; i++)
      {
        total += (nums[i] + mid - 1) / mid; // integer ceil division
      }

      if (total > threshold)
      {
        low = mid + 1; // divisor too small → total too big
      }
      else
      {
        mini = min(mini, mid); // possible answer
        high = mid - 1;        // try smaller divisor
      }
    }

    return mini;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5};
  int threshold = 8;
  int div = sol.smallestDivisor(nums, threshold);
  cout << "The smallest divisor is = " << div << endl;
  return 0;
}