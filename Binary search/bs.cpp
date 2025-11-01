#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }
      else if (nums[mid] < target)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return -1;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {-1, 0, 3, 5, 7, 9};
  int target = 7;
  int index = sol.search(nums, target);
  cout << "The index is = " << index << endl;
  return 0;
}
