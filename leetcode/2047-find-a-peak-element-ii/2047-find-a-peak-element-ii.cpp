class Solution {
public:
int func(vector<vector<int>>& mat,int n,int m,int mid){
int max_value=-1;
int index=-1;
for(int i=0;i<n;i++){
    if(mat[i][mid]>max_value){
        max_value=(mat[i][mid]);
        index=i;
    }
}
return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int n=mat.size();
      int m=mat[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int row=func(mat,n,m,mid);
        int left=mid-1>=0?mat[row][mid-1]:-1;
        int right=mid+1<m?mat[row][mid+1]:-1;
        if(mat[row][mid]>left&&mat[row][mid]>right)return {row,mid};
        else if(mat[row][mid]<right)low=mid+1;
        else
        high=mid-1;
    }
    return {-1,-1};
    }
};