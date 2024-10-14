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
    long long perhour(vector<int>& piles,int mid){
        long long hour = 0;
        for(int i = 0; i < piles.size(); i++) {
            // Use integer arithmetic to avoid floating-point calculations
            hour += (piles[i] + mid - 1) / mid;
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(), piles.end());
        int low=1;
        int high=0;
        high=findMax(piles);
        while(low<=high){
            long long mid = (low+high) / 2;
            if(perhour(piles,mid)<=h)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};