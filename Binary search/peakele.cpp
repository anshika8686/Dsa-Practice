
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int n = nums.size();
    int low = 1, high = n - 2, mid; // this is for boundary
    if (n == 1)
      return 0;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[0] > nums[1])
        return 0; // this is for arr[-1]=-inf()
      if (nums[n - 1] > nums[n - 2])
        return n - 1; // this is for arr[n]=-infinity
      if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
      {
        return mid;
      }
      else if (nums[mid - 1] < nums[mid])
      { // if element is at left of peak then look for right side
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
    return mid;
  }
};
int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 3, 2, 1};
  int peak = sol.findPeakElement(nums);
  cout << "The peak element is = " << peak << endl;
  return 0;
}