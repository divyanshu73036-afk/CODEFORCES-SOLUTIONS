class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
           if(s[i]=='*'){
            if(!st.empty())st.pop();
           }
           else st.push(s[i]);
        }
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};