class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        unordered_map<int, int> myMap;
        for(int i=0;i<intervals.size();i++)
        {
            for(int j=0;j<intervals[i].size();j++)
            {
                if(j==0){
                  start.push_back(intervals[i][j]);
                  myMap[intervals[i][j]]=i;
                }
            }
        }
        vector<int>final;
        sort(start.begin(),start.end());
        for(int i=0;i<intervals.size();i++)
        {
           int left=0;
           int right=start.size()-1;
           int lowest=INT_MAX;
           int ind=-1;
           while(left<=right)
           {
            int mid=left+(right-left)/2;
            if(start[mid]>=intervals[i][1])
            {
                if(lowest>=start[mid])
                {
                    lowest=start[mid];
                    ind=myMap[lowest];
                }
                right=mid-1;
                
            }
            else left=mid+1;
           }
           final.push_back(ind);
        }
    return final;    

    }
};