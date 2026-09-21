class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int k=0;
        for(auto it:mpp){
           int count=min(it.second,2);
           while(count>0){
               nums[k]=it.first;
               k++;
               count--;
           }
            
        }
       //sort(nums.begin(),nums.end());
        return k;
    }
};