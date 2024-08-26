class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++)
        {
            int left=0;
            int right=potions.size()-1;
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(1LL *spells[i]*potions[mid]<success)
                    left=mid+1;
                else right=mid-1;   
            }
            ans.push_back(potions.size()-left);
        }
        return ans;
    }
};