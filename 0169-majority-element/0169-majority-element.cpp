class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());int flag=1;
        int i=0,j=1;
        while(j<nums.size()&&i<j)
        {
            if(nums[i]==nums[j])
            {
                flag++;
                j++;
            }
            else
            {
                if(flag>ceil(nums.size()/2))
                 return nums[i];
                i=j;
                j+=1;
                flag=1; 
            }
        }
        return nums[i];
    }
};