class NumMatrix {
private:
      vector<vector<int>> prefixsums;  
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size()+1;
        int m=matrix[0].size()+1;
        prefixsums= vector<vector<int>>(n,vector<int>(m));
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0)
                    prefixsums[i][j]=0;
                else 
                    prefixsums[i][j]=prefixsums[i][j-1]+prefixsums[i-1][j]-
                    prefixsums[i-1][j-1]+ matrix[i-1][j-1];    
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (prefixsums[row2+1][col2+1]-prefixsums[row1][col2+1]-prefixsums[row2+1][col1]  
        +prefixsums[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */