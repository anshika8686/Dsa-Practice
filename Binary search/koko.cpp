
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end()); // O(nlogn)
        int low = 1, mid, mini = INT_MAX;
        long long total = 0;
        while (low <= high)
        { // O(logn)
            mid = (low + high) / 2;
            total = 0;
            for (int i = 0; i < n; i++)
            { // O(n)
                total = total + (piles[i] + mid - 1) / mid;
            }
            if (total > h)
            {
                low = mid + 1;
            }
            else
            {
                mini = min(mini, mid);
                high = mid - 1;
            }
        }
        return mini;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 10, 12};
    int h = 8;
    int min_speed = sol.minEatingSpeed(nums, h);
    cout << "The minimum speed is = " << min_speed << endl;
    return 0;
}
