#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string>st;
        for(int i=0;i<exp.size();i++)//n
        {
            if((exp[i]>='A'&& exp[i]<='Z')
            ||(exp[i]>='a'&& exp[i]<='z')||
            (exp[i]>='0'&& exp[i]<='9'))
            {
                st.push(string(1,exp[i]));
            }
            else{
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();
                string s='('+top2+exp[i]+top1+')';//o(n)+o(n)
                st.push(s);
            }
        }
        return st.top();
        // tc=o(n),sc=o(n)
    }
};
int main(){
    Solution sol;
    string s="ab*c+";
    string ans=sol.postToInfix(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cin.get();
}
