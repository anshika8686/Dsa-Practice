#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
class Solution {
public:
vector<int>prefix(vector<int>& height){
    int n=height.size();
    vector<int>pre(n);
    pre[0]=height[0];
    for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],height[i]);
    }
    return pre;
}
vector<int>suffix(vector<int>& height){
     int n=height.size();
    vector<int>suf(n);
   
    suf[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],height[i]);
    }
    return suf;

}
    int trap(vector<int>& height) {
         int n=height.size();
         int total=0;
         vector<int>pre=prefix(height);
         vector<int>suf=suffix(height);
        for(int i=0;i<n;i++){
            int leftmax=pre[i];
            int rightmax=suf[i];
            if(height[i]<leftmax && height[i]<rightmax){
                total=total+(min(leftmax,rightmax)-height[i]);
            }
        }
        return total;
    }
};
int trap(vector<int>& height) {
     int n=height.size();
     int l=0,r=n-1;
     int leftmax=0,rightmax=0,total=0;
     while(l<=r){//o(n)
        if(height[l]<=height[r])
        {
            if(leftmax>height[l])
            {
                total=total+(leftmax-height[l]);
            }else{
                leftmax=height[l];
            }
            l++;
        }
        else{
            if(rightmax>height[r])
            {
                total=total+(rightmax-height[r]);
            }else{
                rightmax=height[r];
               
            }
              r--;

        }
       
     }
     return total;
}
};
int main(){
    Solution sol;
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    int total=sol.trap(height);
    return total;
}