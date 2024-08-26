class Solution {
public:
    int arrangeCoins(int n) {
        long long left=1;
        long long right=n;
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long sum=(mid*(mid+1))/2;
            if(sum==n)
             return mid;
            else if(sum>n)
             right=mid-1;
            else
             left=mid+1;  
        }
        return right;
    }
};