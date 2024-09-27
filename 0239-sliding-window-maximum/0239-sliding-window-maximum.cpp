class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            //sliding window size check
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            //if lower than the present number then pop it
            // This ensures that the deque contains the potential     ////    elements for the current window in decreasing order.
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};