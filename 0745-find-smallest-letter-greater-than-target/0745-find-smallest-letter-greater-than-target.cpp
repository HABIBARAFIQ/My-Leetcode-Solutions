template <typename T>
using lettersector = std::vector<T>;
class Solution {
public:
    char nextGreatestLetter(lettersector<char>& letters, char target) {
        unordered_set<char> s(letters.begin(), letters.end());
        letters.assign(s.begin(), s.end()); 
        sort(letters.begin(), letters.end());
        int left=0;
        int right=letters.size()-1;
        if(target>=letters[right])
         return letters[0];
        while(left<=right)
        {
            int mid=left+(right-left)/2;
             if(letters[mid]<=target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return letters[left];

    }
};