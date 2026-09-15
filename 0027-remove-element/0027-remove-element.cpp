class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
			int ptr1=0;
			int ptr2=nums.size()-1;
			if(nums.size()==0)return 0;
			if(nums.size()==1&&val==nums[0])return 0;
			while(ptr2!=ptr1)
			{
				if(val==nums[ptr1])
				{
					nums[ptr1]=nums[ptr2];
					nums[ptr2]=val;
					ptr2--;
				}
				else
				 ptr1++;
			}
			 if(val!=nums[ptr1])
        return ptr1+1;
			 else
			  return ptr1;	
    }
};