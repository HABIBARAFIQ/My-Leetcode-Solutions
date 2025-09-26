class Solution {
    vector<int> v;
public:
    Solution(vector<int>& w) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        v.push_back(w[0]);
        for (int i = 1; i < w.size(); ++i) {
            v.push_back(v.back() + w[i]); // Cumulative SUM
        }
    }
    
    int pickIndex() {
        int rand_weight = rand() % v.back();
        return std::upper_bound(v.begin(), v.end(), rand_weight) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */