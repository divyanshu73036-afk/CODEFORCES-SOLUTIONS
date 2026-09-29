class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&prices[st.top()]>prices[i])  st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        
         for (int i = 0; i < n; i++) {
    if (nse[i] != n) {
        nse[i] = prices[i] - prices[nse[i]];
    } else {
        nse[i] = prices[i];
    }
}
        return nse;

        
    }
};