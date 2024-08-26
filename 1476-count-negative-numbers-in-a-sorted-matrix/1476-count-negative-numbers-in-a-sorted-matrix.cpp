class Solution {
public:
    int countNeginrows (vector<int>&rows)
    {
        int left=0;
        int right=rows.size()-1;
        int indicator=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(rows[mid]>=0)
              left=mid+1;
            else if(rows[mid]<0){
              if(rows[left]>=0)
               left++; 
              else return (right-left)+1; 
              }
        }
        return 0;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int total=0;
        for(int i=0;i<grid.size();i++)
        {
             total+=countNeginrows(grid[i]);
        }
        return total;
    }
};