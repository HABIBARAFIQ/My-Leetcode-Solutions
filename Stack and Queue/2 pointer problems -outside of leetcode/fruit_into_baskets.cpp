
//You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array of fruits, return the maximum number of fruits you can pick.



// Input: arr[]= [2, 1, 2]
// Output: 3
// Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.
// Input: arr[] = [3, 1, 2, 2, 2, 2]
// Output: 5
// Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int maxlength=0;
        int len=0;
        int right=0;
        int left=0;
        int type1=0;
        int type2=0;
        unordered_map<int,int>bask;
        
        while(right<arr.size()){
            bask[arr[right]]++;
            if(bask.size()>2)
            {
                bask[arr[left]]--;
                if(bask[arr[left]]==0)bask.erase(arr[left]);
                left++;
            }
            if(bask.size()<=2){
            len=right-left+1;
            maxlength=max(maxlength,len);
            }
            right++;
        }
        return maxlength;
    }
};
