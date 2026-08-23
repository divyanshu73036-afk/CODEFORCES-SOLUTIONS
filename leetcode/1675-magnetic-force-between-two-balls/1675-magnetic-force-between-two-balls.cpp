class Solution {
public:
bool can_we_place(vector<int>& a,int force ,int balls ){
    int countball=1;
    int firstball=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]-firstball>=force){
            countball++;
            firstball=a[i];

        }
        if(countball>=balls)return true;
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();//total number of baskets
        //m is balls needs to distribute
        int low=1;
        int high=position[n-1]-position[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if (can_we_place(position,mid,m)==true){
                low=mid+1;
            }
            else high=mid-1;
        }
        return high;

    }
};