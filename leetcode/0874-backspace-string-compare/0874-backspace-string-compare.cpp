class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> fors, fort;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!fors.empty())
                    fors.pop();
            }
            else {
                fors.push(s[i]);
            }
        }

        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!fort.empty())
                    fort.pop();
            }
            else {
                fort.push(t[i]);
            }
        }

        return fors == fort;
    }
};