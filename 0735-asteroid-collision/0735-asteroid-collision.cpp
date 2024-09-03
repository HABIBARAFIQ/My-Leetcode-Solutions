class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(asteroids[i])) {
                    st.pop();
                } else if (abs(st.top()) == abs(asteroids[i])) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }
        while (!st.empty()) {
            result.insert(result.begin(), st.top());
            st.pop();
        }
        return result;
    }
};