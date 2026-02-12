#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        map<int,int>mpp;
        stack<int>st;
        vector<int>ans;
        for(int i=nums2.size()-1;i>=0;i--){//o(n2)
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                    if(st.empty()){
                        mpp[nums2[i]]=-1;
                    }
                    else
                    {
                 mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){//o(n1)
                    ans.push_back(mpp[nums1[i]]);
            }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums1={4,1,2};
    vector<int>nums2={1,3,4,2};
    vector<int> ans=sol.nextGreaterElement(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<","<<" ";
    }
    cin.get();
}