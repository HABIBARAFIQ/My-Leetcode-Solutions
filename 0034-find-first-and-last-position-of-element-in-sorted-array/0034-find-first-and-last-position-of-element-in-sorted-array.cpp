class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int left=0;
       int right=nums.size()-1;
       int start=-1;
       int end=-1;
       vector<int>stend;
       while(left<=right)
       {
        int mid=left+(right-left)/2;
        if(nums[mid]<target)
          left=mid+1;
        else if(nums[mid]>target)
          right=mid-1;
        else if(nums[mid]==target)
        {
            if(nums[left]==target&&start<0)
            {
                start=left;
            }
            else left++;
            if(nums[right]==target&&end<0)
            {
                end=right;
            }
            else right--; 
        }
        }  
        stend.push_back(start);
        stend.push_back(end);
       return stend; 
       }
};