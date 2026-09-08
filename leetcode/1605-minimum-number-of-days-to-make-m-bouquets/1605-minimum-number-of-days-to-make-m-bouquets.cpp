class Solution {
public:
int possible(vector<int>arr,int day,int m,int k){
    int count=0;
    int numberofB=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            count++;
        }
        else{
            
            numberofB+=(count/k);
            count=0;
        }
    }
    numberofB+=(count/k);
    if(numberofB>=m)return true;
    else return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()) return -1;
      int maxi=INT_MIN;
      for(int i=0;i<bloomDay.size();i++){
                maxi=max(maxi,bloomDay[i]);
      }
      int low=1;
      int high=maxi;
int ans=high;
while(low<=high){
    int mid=low+(high-low)/2;
    if(possible(bloomDay,mid,m,k)){
        ans=mid;
        high=mid-1;

    }
    else low=mid+1;
}
return low;//or ans
    }
};