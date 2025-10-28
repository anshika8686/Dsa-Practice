#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size(), mid, maxi = -1, mini = -1;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                mini = mid;
                high = mid - 1; // move towards left to get first occurence
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

        low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                maxi = mid;
                low = mid + 1; // move towards right to get last occurence
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
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> ans;
    vector<int> nums = {1, 3, 3, 5, 6};
    int target = 3;
    ans = sol.searchRange(nums, target);
    cout << "The range is = " << endl;
    for (auto &it : ans)
    {
        cout << it << endl;
    }
    return 0;
}