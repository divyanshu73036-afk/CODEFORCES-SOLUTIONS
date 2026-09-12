class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
             // Opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if(st.empty())return false;
                else {
                   char ch=st.top();
                 //  st.pop();
                   if(s[i]==')'&&ch=='('||s[i]=='}'&&ch=='{'||s[i]==']'&&ch=='['){
                        st.pop();
                   }
                   else return false;
                }
            }
        }
        //at last stack shoul be empty for valid parenthesis
        return   st.empty();
        }

};