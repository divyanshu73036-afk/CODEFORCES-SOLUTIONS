class Solution {
public:
int nge(vector<int>& arr,int index){
    int n=arr.size();
    vector<int>new1(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=arr[i]) st.pop();
            
            if(st.empty())new1[i]=-1;
            else new1[i]=st.top();
            st.push(arr[i]);
        
    }
    return new1[index];
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> new2(n);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    new2[i]=nge(nums2,j);
                }
            }
        }
        return new2;
    }
};