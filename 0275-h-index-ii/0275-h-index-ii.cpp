class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0;
        int right=citations.size()-1;
        int s=citations.size();
        int ans=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(citations[mid]>=(s-mid))
             {
                ans=s-mid;
                right=mid-1;
             }
             else
              left=mid+1;
        }
        return ans;

    }
};