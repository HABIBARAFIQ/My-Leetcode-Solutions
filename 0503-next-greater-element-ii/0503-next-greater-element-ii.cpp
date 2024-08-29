class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size=nums.size();
        vector<int>nge;
        nge.resize(size,-1);
        nge.resize(size);
        stack<int>st;
        for(int i= 2*size-1;i>=0;i--)
        {
            while(!st.empty()&&nums[i%size]>=st.top())
            {
                st.pop();
            }
            if(!st.empty()&&i<size)
            {
                nge[i]=st.top();
            }
            st.push(nums[i%size]);
        }
        return nge;
    }
};