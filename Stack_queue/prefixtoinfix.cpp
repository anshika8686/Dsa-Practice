#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 string preToInfix(string pre_exp) {
stack<string>st;
        for(int i=pre_exp.size()-1;i>=0;i--)//n
        {
            if((pre_exp[i]>='A'&& pre_exp[i]<='Z')
            ||(pre_exp[i]>='a'&& pre_exp[i]<='z')||
            (pre_exp[i]>='0'&& pre_exp[i]<='9'))
            {
                st.push(string(1,pre_exp[i]));
            }
            else{
                string top1=st.top();
                st.pop();
                string top2=st.top();
                st.pop();
                string s='('+top1+pre_exp[i]+top2+')';//o(n)+o(n)
                st.push(s);
            }
        }
        return st.top();
        // tc=o(n),sc=o(n)
    }
    };
int main(){
    Solution sol;
    string s="*-A/BC-/AKL";
    string ans=sol.preToInfix(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cin.get();
}
