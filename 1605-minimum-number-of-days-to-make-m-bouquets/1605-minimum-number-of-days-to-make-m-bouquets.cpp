class Solution {
public:
    int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;

}
    int findMin(vector<int> &v) {
    int mini = INT_MAX;
    int n = v.size();
    //find the minimum:
    for (int i = 0; i < n; i++) {
        mini = min(mini, v[i]);
    }
    return mini;
    
}
    int countdays(vector<int>& bloomDay,long long mid,int k){
        int count=0;
        int nobuq=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid)
            {
                count++;
            }
            else{
                nobuq+=(count/k);
                count=0;
            }
        }
        nobuq += (count / k);
        return nobuq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=findMin(bloomDay);
        int high=findMax(bloomDay);
        while(low<=high){
            long long mid=(low+high)/2;
            if(countdays(bloomDay,mid,k)>=m)
            {
                high=mid-1;
            }
            else low=mid+1;
        }
        if (countdays(bloomDay, low, k) >= m) {
            return low;
        }
        return -1;
        

    }
};