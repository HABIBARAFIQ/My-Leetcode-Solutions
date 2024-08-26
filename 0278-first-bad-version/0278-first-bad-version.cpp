// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1;
        long long right=n;
        long long bad=INT_MAX;

        //1+(4-1)/2=1+1=2
        //1+(3-1)/2=1+1=2
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(isBadVersion(mid))
            {
                bad=mid;
                right=mid-1;
            }
            else{
                if(isBadVersion(left)){
                    bad=left;
                    break;
                }
                else if(isBadVersion(right))
                {
                    bad=right;
                    right--;
                }
                left=mid+1;
            }
        }
        return bad;
    }
};