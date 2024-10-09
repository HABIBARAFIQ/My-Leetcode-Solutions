class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>map;
        int left=0;
        int right=0;
        int substrings=0;
        // while(right<s.size()){
        //     map[s[right]]++;
        //     while(map['a'] > 0 && map['b'] > 0 && map['c'] > 0){
        //         substrings+=(s.size()-right);
        //         // if(map[s[left]]==0)map.erase(map[s[left]]);
        //         map[s[left]]--;
        //         left++;
        //     }
        //     right++;
        // }
        // can do more optimize
        int lastseen[3]={-1,-1,-1};
        while(right<s.size()){
            lastseen[s[right] - 'a'] = right;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                int min_last_seen = min(lastseen[0], min(lastseen[1], lastseen[2]));
                substrings += (min_last_seen + 1);
            }
            right++;
        }
        return substrings;
    }
};