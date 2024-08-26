class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
		int left = 0;
		int right = n - 1;
		int mid = 0;
		int target = INT_MAX;
		while (left <= right) {
			mid = (left + right) / 2;
            if(nums[left]<=nums[right]){
                target=min(target,nums[left]);
                break;
                }
            if(nums[left]<=nums[mid]){
                target=min(target,nums[left]);
                left=mid+1;
            }
            else
            {
                target=min(target,nums[mid]);
                right=mid-1;
            }    

		}
    return target;
    }
};