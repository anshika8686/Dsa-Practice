#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int lowerBound(vector<int> &arr, int target)
  {
    // code here
    int n = arr.size();
    int mini = n;
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (arr[mid] >= target)
      {
        mini = min(mini, mid);
        high = mid - 1; // i needed a smallest index
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
  vector<int> nums = {2, 3, 7, 10, 11, 11, 25};
  int target = 11;
  int index = sol.lowerBound(nums, target);
  cout << "The lower bound is = " << index << endl;
  return 0;
}
