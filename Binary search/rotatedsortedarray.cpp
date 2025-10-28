#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    int mid = -1, low = 0, high = n - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      if (nums[low] <= nums[mid]) // right half sorted
      {
        if (nums[low] <= target && target < nums[mid])
        { // target is there in right half
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }
      else
      {
        if (nums[mid] < target && target <= nums[high])
        { // target present in left half
          low = mid + 1;
        }
        else
        {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 2;
  int index = sol.search(nums, target);
  cout << "The index is = " << index << endl;
  return 0;
}