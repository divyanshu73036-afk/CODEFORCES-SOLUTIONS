class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();

        k = n - k;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && st.top() > nums[i]) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        vector<int> res;

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};