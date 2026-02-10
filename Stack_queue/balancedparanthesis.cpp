#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) 
    {
        stack<int>st;
        if(s.size()==1){
            return false;
        }
        for(int i=0;i<s.size();i++){ //o(n)
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                return false;
                if(s[i]==')'&& st.top()=='(' || s[i]=='}'&& st.top()=='{'||s[i]==']'&& st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
    }
        if(!st.empty()){
        return false;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    string s="({}){}[]";
    bool ans=sol.isValid(s);
    cout<<boolalpha<<ans;
    return 0;
}