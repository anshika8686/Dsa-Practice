#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int area=0;
        stack<int>st;
        int ele,pse,nse;
        int n=heights.size();
       for(int i=0;i<heights.size();i++){//o(n)
        while(!st.empty() && heights[st.top()]>heights[i]){
            ele=heights[st.top()];
            st.pop();
             pse=st.empty()?-1:st.top();
            nse=i;
             area=max(area,(ele*(nse-pse-1)));
        }
        st.push(i);
       }
       while(!st.empty()){
        ele=heights[st.top()];
        st.pop();
        pse=st.empty()?-1:st.top();
        nse=n;
       area=max(area,(ele*(nse-pse-1)));
       }
       return area; //o(3n) tc
       //o(n) sc

    }
};
int main(){
    Solution sol;
    vector<int>heights={2,1,5,6,2,3};
    int area=sol.largestRectangleArea(heights);
    cout<<"Area of largest rectangle"<<area;
    return 0;
}