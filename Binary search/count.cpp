#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countFreq(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size(), first = -1, last = -1;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == target)
            {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < target)
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
            if (arr[mid] == target)
            {
                last = mid + 1;
                low = mid + 1;
            }
            else if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return last - first;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 3, 3, 5, 6};
    int target = 3;
    int index = sol.countFreq(nums, target);
    cout << "The frequency is = " << index << endl;
    return 0;
}
