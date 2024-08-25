class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int high = nums.size() - 1;
        if(nums.size()==1||nums[0]!=nums[1])return nums[0];
        if(nums[high]!=nums[high-1])return nums[high];
        while ( left<=high) {
            int mid = left + (high - left) / 2;
            if (( nums[mid - 1] != nums[mid]) &&
                ( nums[mid + 1] != nums[mid])) {
                return nums[mid];
            } else if ( nums[mid - 1] == nums[mid]) {
                if (mid % 2 == 0) {
                    high = mid - 1;
                } else {
                    left = mid + 1;
                }

            } else if ( nums[mid + 1] == nums[mid]) {
                if (mid % 2 == 0) {
                    left = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};