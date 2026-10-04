class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> mp;

        for(auto x : trust) {
            mp[x[0]]--;   // person x[0] trusts someone
            mp[x[1]]++;   // person x[1] is trusted
        }

        for(int i = 1; i <= n; i++) {
            if(mp[i] == n - 1)     return i;
        }

        return -1;
    }
};