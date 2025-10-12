#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        string ans = "";
        map<char, int> hashmap;
        for (char ch : s)
        {
            hashmap[ch]++;
        }
        vector<pair<char, int>> hashvec(hashmap.begin(), hashmap.end());
        sort(hashvec.begin(), hashvec.end(), [](pair<char, int> &a, pair<char, int> &b)
             {
            //  if (a.second == b.second)
            //     return a.first > b.first;
            return a.second>b.second; });
        for (auto &it : hashvec)
        {
            ans.append(it.second, it.first); // append-> second=no of times, first=it will apeend that much no of times
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "tree";
    string ans = sol.frequencySort(s);
    cout << ans << endl; //  prints "true" or "false"
    return 0;
}