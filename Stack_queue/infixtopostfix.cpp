#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
  int priority(char ch){
    if(ch=='^'){
        return 3;
    }
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    return -1;
}
    string infixToPostfix(string& s) {
        // code here
        string ans;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if((s[i]>='A'&& s[i]<='Z')
            ||(s[i]>='a'&& s[i]<='z')||
            (s[i]>='0'&& s[i]<='9')){
                ans=ans+s[i];
            }
            else if(s[i]=='('){
            st.push(s[i]);
            }
            else if(s[i]==')')
            {
                while(!st.empty()&& st.top()!='('){
                    ans=ans+st.top();
                    st.pop();
                }
                if(!st.empty()){
                st.pop(); }
            }
            else {
              while(!st.empty() &&
               (priority(s[i]) < priority(st.top()) ||
                (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
                 ans += st.top();
                 st.pop();
    }  
    st.push(s[i]);
}
    }
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
    return ans;
    
    }
};
int main(){
    Solution sol;
    string s="a+b*(c^d-e)^(f+g*h)-i";
    string ans=sol.infixToPostfix(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cin.get();
}
