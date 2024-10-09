class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>map;
        int left=0;
        int right=0;
        int substrings=0;
        while(right<s.size()){
            map[s[right]]++;
            while(map['a'] > 0 && map['b'] > 0 && map['c'] > 0){
                substrings+=(s.size()-right);
                // if(map[s[left]]==0)map.erase(map[s[left]]);
                map[s[left]]--;
                left++;
            }
            right++;
        }
        return substrings;
    }
};