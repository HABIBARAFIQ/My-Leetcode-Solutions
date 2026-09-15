class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
			int ptr1 = 0; 
    int ptr2 = 1;int counter=0;
		if(nums.size()==1)return nums.size();

		while(ptr2<nums.size())
		{
			if(nums[ptr1]!=nums[ptr2])
			{
				ptr1++;
				nums[ptr1] = nums[ptr2];
			}
			 ptr2++;
		}
		return ptr1+1;
    }
};