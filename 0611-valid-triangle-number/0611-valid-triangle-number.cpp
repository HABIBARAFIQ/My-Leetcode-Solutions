class Solution {
public:
    int triangle(vector<int>& nums,int low,int high,int k){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<k)
                low=mid+1;
            else high=mid-1;    
        }
        return high;
    }
    int triangleNumber(vector<int>& nums) {
        int ans =0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++){
                int idx=triangle(nums,j+1,nums.size()-1,nums[i]+nums[j]);
                int k=idx-j;
                ans+=k;
            }
        }
        return ans;
    }
};