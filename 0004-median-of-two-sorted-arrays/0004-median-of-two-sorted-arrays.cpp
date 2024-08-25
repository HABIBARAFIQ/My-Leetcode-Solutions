class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
    int m = nums2.size();
    if (n > m)
        return findMedianSortedArrays(nums2, nums1);
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA
            = (leftAsize > 0)
                  ? nums1[leftAsize - 1]
                  : INT_MIN;
        int leftB
            = (leftBsize > 0) ? nums2[leftBsize - 1] : INT_MIN;
        int rightA
            = (leftAsize < n) ? nums1[leftAsize] : INT_MAX;
        int rightB
            = (leftBsize < m) ? nums2[leftBsize] : INT_MAX;
        if (leftA <= rightB and leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB)
                        + min(rightA, rightB))
                       / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB) {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
    }
};