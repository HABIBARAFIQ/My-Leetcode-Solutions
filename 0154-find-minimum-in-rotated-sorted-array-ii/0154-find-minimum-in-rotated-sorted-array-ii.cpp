class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
		int left = 0;
		int right = n - 1;
		int mid = 0;
		int target = INT_MAX;
        int count=0;
		while (left < right) {
			mid = (left + right) / 2;
           if(nums[mid]<nums[right])
            right=mid;
           else if(nums[mid]>nums[right])
            left=mid+1;
           else right--;     

		}
    return nums[left];
    }
};