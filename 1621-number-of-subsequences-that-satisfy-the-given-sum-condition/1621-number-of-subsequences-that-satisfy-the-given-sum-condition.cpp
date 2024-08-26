class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int count=0;
        int left=0;
        int right=nums.size()-1;
        int size=nums.size();
        vector<int>powerofnums(size);
        int mod=1000000007;
        powerofnums[0]=1;
        for(int i=1;i<size;i++)
        {
            powerofnums[i]=(2*powerofnums[i-1])%mod;
        }
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                count=(count+powerofnums[right-left])%mod;
                left++;
            }
            else right--;
        }
        return count;
    }
};