class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        int left = 0;
        int right = 0;
        int min_len = INT_MAX;
        int min_start = 0;
        string result_str = "";
        unordered_map<char, int> freqmap1;
        unordered_map<char, int> freqmap2;
        int formed = 0;
        for (int i = 0; i < t.size(); i++) {
            freqmap2[t[i]]++;
        }
        while (right < s.size()) {
            freqmap1[s[right]]++;
            if (freqmap2.find(s[right]) != freqmap2.end() &&
                freqmap1[s[right]] == freqmap2[s[right]]) {
                formed++;
            }
            while (left <= right && formed == freqmap2.size()) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;//6
                    min_start = left;//0
                }

                // Shrink the window from the left
                char left_char = s[left];
                freqmap1[left_char]--;

                // If the character removed is part of `t` and its frequency
                // falls below the required amount, decrease `formed`
                if (freqmap2.find(left_char) != freqmap2.end() &&
                    freqmap1[left_char] < freqmap2[left_char]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }
};