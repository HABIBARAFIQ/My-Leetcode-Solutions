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
            next_smaller[i] = st.empty() ?A.size() : st.top();
            st.push(i);
        }
        return next_smaller;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int min = 0;
        long long mod = 1000000007;
        vector<int> result_pse = pse(arr);
        vector<int> result_nse = nse(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - result_pse[i];
            long long right = result_nse[i] - i;
            min = (min + (left * right * arr[i]) % mod) % mod;
        }
        return min;
    }
};