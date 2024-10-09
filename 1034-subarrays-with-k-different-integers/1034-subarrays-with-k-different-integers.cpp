class Solution {
public:
    int countSubarraysWithAtMostSum(vector<int>& nums, int goal) {
        int left = 0, right = 0;
        int64_t sum = 0; // int64_t to prevent overflow
        int count = 0;
        unordered_map<int,int>subar;
        while (right < nums.size()) {
            subar[nums[right]]++;
            while (subar.size() > goal && left <= right) {
                subar[nums[left]]--;
                if(subar[nums[left]]==0)subar.erase(nums[left]);
                left++;
            }
            if (subar.size() <= goal)
                count += right - left + 1;
            right++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        return countSubarraysWithAtMostSum(nums, k) -
               countSubarraysWithAtMostSum(nums, k - 1);
    }
};