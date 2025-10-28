#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        // code here
        int n = arr.size(), mid;
        int low = 0, high = n - 1, maxi = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] <= x)
            {
                maxi = max(maxi, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return maxi;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 3, 3, 5, 6}; // floor targets the last index
    int target = 4;
    int index = sol.findFloor(nums, target);
    cout << "The index is = " << index << endl;
    return 0;
}