class Solution {
public:
    // Helper function to count subarrays with at most the given sum
    int countSubarraysWithAtMostSum(vector<int>& nums, int goal) {
        int left = 0, right = 0;
        int64_t sum = 0;  // int64_t to prevent overflow
        int count = 0;

        while (right < nums.size()) {
            sum += nums[right];
            while (sum > goal&& left <= right) {
                sum -= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0)return 0;
        return countSubarraysWithAtMostSum(nums, goal) - 
               countSubarraysWithAtMostSum(nums, goal - 1);
    }
};
