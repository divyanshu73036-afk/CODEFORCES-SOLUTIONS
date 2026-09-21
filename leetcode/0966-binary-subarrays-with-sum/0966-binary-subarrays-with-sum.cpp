class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int,int>mpp;
      int prefix=0;
      int ans=0;
      mpp[0]=1;
      for(int i=0;i<nums.size();i++){
        prefix+=nums[i];
        ans+=mpp[prefix-goal];
        mpp[prefix]++;
      } 
      return ans; 
    }
};