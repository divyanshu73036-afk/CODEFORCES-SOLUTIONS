class Solution {
public:
int findmax(vector<int>& piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        if(piles[i]>maxi)maxi=piles[i];
    }
    return maxi;
}
long long calculateTH(vector<int>& piles, int hourly){
   
    long long totalH=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        totalH+=ceil((double)piles[i]/(double)hourly);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhour=calculateTH(piles,mid);
            if(totalhour<=h){
                ans=mid;
                high=mid-1;

            }
            else low=mid+1;
        }
        return low;
    }
};