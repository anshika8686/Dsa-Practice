#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // long long subArrayRanges(vector<int>& nums) 
    // {
    //     int n=nums.size();
    //     long long sum=0;
    //     for(int i=0;i<n;i++){
    //         int mini=maxi=arr[i];
    //         for(int j=i;j<=n;j++){
    //             mini=min(mini,nums[j]);
    //             maxi=max(maxi,nums[j]);
    //             sum=sum+(max-min);
    //         }
    //     }
    //     return sum;
    // }

    vector<int>psee(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size());
    for(int i=0;i<arr.size();i++){//o(n)
        while(!st.empty() && arr[st.top()]>arr[i]){
            //remove equals to sign to avoid duplicate subarray count o(n)
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top();
        }
         st.push(i);
    }
    return ans;
   }

    vector<int>nse(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){//o(n)
        while(!st.empty() && arr[st.top()]>=arr[i]){//o(n)
            st.pop();
        }
        if(st.empty()){
            ans[i]=arr.size();
        }else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
 }

    vector<int>pge(vector<int>&arr){
    stack<int>st;
     vector<int>ans(arr.size());
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=st.top(                            );
        }
        st.push(i);
    }
    return ans;
}

vector<int>nge(vector<int>&arr){
    stack<int>st;
     vector<int>ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=arr.size();
        }else{
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}

long long minimum(vector<int>&nums){
    vector<int>prev=psee(nums);
    vector<int>next=nse(nums);
    long long total=0;
    for(int i=0;i<nums.size();i++){
        int p=i-prev[i];
        int n=next[i]-i;
       total=total+ (long long)p*n*nums[i]*1LL;
    }
    return total;
}

long long maximum(vector<int>&nums){

    vector<int>prev=pge(nums);
    vector<int>next=nge(nums);
    long long total=0;
    for(int i=0;i<nums.size();i++){
        int p=i-prev[i];
        int n=next[i]-i;
        total=total+ (long long)p*n*nums[i]*1LL;
    }
    return total;
}

    long long subArrayRanges(vector<int>& nums) 
    {
        long long max=maximum(nums);
        long long min=minimum(nums);
        long long diff=max-min;
        return diff;
    }
};
int main(){
    Solution sol;

    vector<int> arr = {3, 1, 2, 4};

    cout << sol.subArrayRanges(arr) << endl;

    return 0;
}