class Solution {
public:
    string smallestSubsequence(string s) {
         stack<char> st;
        vector<int> last(26, 0);
        vector<bool> vis(26, false);

        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            if (vis[s[i] - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() - 'a' > s[i] - 'a' &&
                   last[st.top() - 'a'] > i) {

                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i] - 'a'] = true;
        }

        string ans = "";

        while (st.size() > 0) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};