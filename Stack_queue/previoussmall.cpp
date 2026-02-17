#include<bits/stdc++.h>
vector<int>pse(vector<int>&arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=arr[i];
        }
    }
    return ans;
}
vector<int>pge(vector<int>&arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=arr[i];
        }
    }
    return ans;
}
vector<int>nse(vector<int>&arr){
    stack<int>st;
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=arr[i];
        }
    }
    return ans;
}
vector<int>nge(vector<int>&arr){
    stack<int>st;
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }else{
            ans[i]=arr[i];
        }
    }
    return ans;
}

