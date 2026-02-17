#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
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
    int sumSubarrayMins(vector<int>& arr) 
    {
        long long total=0;
        int mod=(int)1e9+7;
     vector<int>prev=psee(arr);//o(2n)
      vector<int>next=nse(arr);//o(2n)
      for(int i=0;i<arr.size();i++){//o(n)
        int p=i-prev[i];
        int n=next[i]-i;
       total = (total + ((1LL * p * n % mod) * arr[i] % mod)) % mod;
      }
      return total;
    }
};
// ; tc=o(5n) sc=o(5n)