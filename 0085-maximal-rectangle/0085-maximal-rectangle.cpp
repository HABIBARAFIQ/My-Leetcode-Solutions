class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pre_sum(n, vector<int>(m, 0));
        int max_area = 0;
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '0')
                    sum = 0;
                else
                    sum += 1;
                pre_sum[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, largestRectangleArea(pre_sum[i]));
        }
        return max_area;
    }
};