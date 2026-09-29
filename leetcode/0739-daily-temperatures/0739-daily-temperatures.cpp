class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;//stores indexx
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&temperatures[st.top()]<=temperatures[i])st.pop();
            nge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(nge[i]==-1){
                nge[i]=0;
            }
            else{
                nge[i]=nge[i]-i;
            }
        }
        return nge;
    }
};