class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = k;
        if (num.size() == k)
            return "0";
        else {
            stack<char> st;
            for (int i = 0; i < num.size(); i++) {
                while (!st.empty() && st.top() > num[i] && n > 0) {
                    st.pop();
                    n--;
                }
                st.push(num[i]);
            }
            while (n > 0) {
                st.pop();
                n--;
            }
            deque<char> res;
            while (!st.empty()) {
                res.push_front(st.top());
                st.pop();
            }
            while (!res.empty() && res.front() == '0') {
                res.pop_front();
            }
            if (res.empty()) {
            return "0";
            }
            string str(res.begin() , res.end());
            return str;
        }
    }
}
;