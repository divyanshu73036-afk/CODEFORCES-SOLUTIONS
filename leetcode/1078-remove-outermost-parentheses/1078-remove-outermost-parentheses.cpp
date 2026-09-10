class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";//empty string

        stack<char>st;
        for(char it:s){
                        if(it==')')st.pop();

            if(!(st.empty()))ans+=it;
                        if(it=='(')st.push(it);
                      //  if(it==')')st.pop();

        
        }
        return ans;

    }
};