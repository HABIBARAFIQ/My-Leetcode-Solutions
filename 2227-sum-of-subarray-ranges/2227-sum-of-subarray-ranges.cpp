class Solution {
private:
    vector<int> pse(vector<int>& A) {
        int n = A.size();
        vector<int> prev_smaller(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev_smaller[i] = st.top();
            }
            st.push(i);
        }
        return prev_smaller;
    }
    vector<int> nse(vector<int>& A) {
        vector<int> next_smaller;
        next_smaller.resize(A.size());
        stack<int> st;
        for (int i = A.size() - 1; i >= 0; i--) {
            while (!st.empty() && A[st.top()] > A[i]) {
                st.pop();
            }
            next_smaller[i] = st.empty() ? A.size() : st.top();
            st.push(i);
        }
        return next_smaller;
    }
    vector<int> nge(vector<int>& A) {
        int n = A.size();
        vector<int> nge_A(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && A[st.top()] <= A[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge_A[i] = st.top();
            }
            st.push(i);
        }
        return nge_A;
    }

    vector<int> pge(vector<int>& A) {
        int n = A.size();
        vector<int> result(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && A[s.top()] < A[i]) {
                s.pop();
            }
            if (!s.empty()) {
                result[i] = s.top();
            }
            s.push(i);
        }
        return result;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long min_1 = 0;
        long long max_1 = 0;
        vector<int> result_pse = pse(nums);
        vector<int> result_nse = nse(nums);
        for (int i = 0; i < n; i++) {
            long long left = i - result_pse[i];
            long long right = result_nse[i] - i;
            min_1 = min_1 + (left * right * nums[i]);
        }
        vector<int> result_pge = pge(nums);
        vector<int> result_nge = nge(nums);
        for (int i = 0; i < n; i++) {
            long long left = i - result_pge[i];
            long long right = result_nge[i] - i;
            max_1 = max_1 + (left * right * nums[i]);
        }
        return (max_1 - min_1);
    }
};