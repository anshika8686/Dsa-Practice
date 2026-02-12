#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>st;
        string ans;
        for(int i=0;i<post_exp.size();i++){
            if((post_exp[i]>='A'&& post_exp[i]<='Z')
            ||(post_exp[i]>='a'&& post_exp[i]<='z')
            ||(post_exp[i]>='0'&& post_exp[i]<='9'))
            {
                st.push(string(1,post_exp[i]));
            }
            else{
            string st1=st.top();
            st.pop();
            string st2=st.top();
            st.pop();
            ans=post_exp[i]+st2+st1;
            st.push(ans);
        }
    }
    return st.top();
    }
};
int main(){
    Solution sol;
    string s="ABC/-AK/L-*";
    string ans=sol.postToPre(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}