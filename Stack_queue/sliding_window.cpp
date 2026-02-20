#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
    int n=nums.size();
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<n;i++){//o(n)
    while(!dq.empty() && dq.front()<=i-k){//o(n) removing extra window elements
        dq.pop_front();
    }
    while(!dq.empty() && nums[dq.back()]<=nums[i]){//keeping only maxi
        dq.pop_back();//o(n)
    }   
    dq.push_back(i);
    if(i>=k-1){ //push all the elements reaching upto k
        ans.push_back(nums[dq.front()]);
    }
    }
    return ans;
    }
};
int main(){
    Solution sol;
    vector<int>ans;
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    ans=sol.maxSlidingWindow(arr,k);
    for(auto it:ans)
    cout << it<< endl;

    return 0;
}

 