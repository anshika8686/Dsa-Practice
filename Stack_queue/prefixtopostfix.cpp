#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  string preToPost(string pre_exp) {
        stack<string>st;
        string ans;
        for(int i=pre_exp.size()-1;i>=0;i--){
            if((pre_exp[i]>='A'&& pre_exp[i]<='Z')
            ||(pre_exp[i]>='a'&& pre_exp[i]<='z')||
            (pre_exp[i]>='0'&& pre_exp[i]<='9'))
            {
                st.push(string(1,pre_exp[i]));
            }
            else{
            string st1=st.top();
            st.pop();
            string st2=st.top();
            st.pop();
            ans=st1+st2+pre_exp[i];
            st.push(ans);
        }
    }
    return st.top();
    } 
};
int main(){
    Solution sol;
    string s="*-A/BC-/AKL";
    string ans=sol.preToPost(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}