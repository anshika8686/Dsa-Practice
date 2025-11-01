#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();
    int low = 0, high = n - 1, mini = nums[0];
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[low] <= nums[high])
      {
        mini = min(mini, nums[low]);
        break;
      }
      if (nums[low] <= nums[mid])
      {
        mini = min(mini, nums[low]);
        low = mid + 1; // this will look in right half if left half is sorted
      }
      else
      {
        mini = min(mini, nums[mid]);
        high = mid - 1; // acc to right half mid will be smallest , this will look into left half
      }
    }
    return mini;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {5, 0, 1, 2, 3, 4};
  int mini = sol.findMin(nums);
  cout << "The minimum is = " << mini << endl;
  return 0;
}
