class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sub;  
    for (int num : nums) {
        // binary search to find the position of num in sub
        auto it = lower_bound(sub.begin(), sub.end(), num);
        // If num is larger than all elements, it will be placed at the end
        if (it == sub.end()) {
            sub.push_back(num);
        } else {
            // Otherwise, replace the element at the found position
            *it = num;
        }
    }

    // The size of the 'sub' array will give us the length of the longest increasing subsequence
    return sub.size();
    }
};