class Solution {
public:
    bool check(int mid,int period, vector<int>& lights, vector<int>& arrivalTime){
        
        int maxLight=*max_element(lights.begin(),lights.end());
        for(int i=0;i,i<arrivalTime.size();i++){
            int r=arrivalTime[i] % period;
            int wait=0;
                
                if(r>=maxLight)wait=period-r;
            if(wait>mid)return false;
            
        }
        return true;
    }
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int low=0;
        int high=period-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,period,lights,arrivalTime))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};