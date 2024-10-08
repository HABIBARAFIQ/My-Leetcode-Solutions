class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlength = 0;
        int len = 0;
        int right = 0;
        int left = 0;
        unordered_map<char, int> lpc;
        int maxFreq = 0;
        int conv = 0;
        // If the window contains n characters, and the most frequent character
        // appears maxFreq times, then   the other n - maxFreq characters would
        // need to be replaced to match the most frequent character.
        while(right<s.length()){
        lpc[s[right]]++;
        maxFreq = max(lpc[s[right]], maxFreq);
        if (right - left + 1 - maxFreq > k) {
            lpc[s[left]]--;
            left++;
        }
        len = right - left + 1;
        maxlength = max(maxlength, len);
        right++;
    }
    return maxlength;
}
}
;