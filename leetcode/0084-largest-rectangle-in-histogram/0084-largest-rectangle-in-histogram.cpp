class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

    stack<int>st;
    int max_area=0;
     int n=heights.size();
     for(int i=0;i<n;i++){
        while(!st.empty()&&heights[st.top()]>heights[i]){
            int element_ind=st.top();
            st.pop();
         int    nse=i;
         int   pse=st.empty() ? -1 : st.top();
            max_area = max(max_area, heights[element_ind] * (nse - pse - 1));
        }
        st.push(i);
      }
      while(!st.empty()){
        int nse=n;
       int  element_ind=st.top();
       st.pop();
                int   pse=st.empty() ? -1 : st.top();
                max_area = max(max_area, heights[element_ind] * (nse - pse - 1));
      }
      return max_area;
}
};