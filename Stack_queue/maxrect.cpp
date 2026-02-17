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
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int row=matrix.size();
        int col=matrix[0].size();
        int maxArea=0;
        vector<int>ans(col,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    ans[j]=ans[j]+1;
                }else{
                    ans[j]=0;
                }
            }
            int maxi=largestRectangleArea(ans);
            maxArea=max(maxArea,maxi);
    }
    return maxArea;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
};

    int number=sol.maximalRectangle(matrix);
    cout<<"Maximum number of rectangle"<<number;
    return 0;


}