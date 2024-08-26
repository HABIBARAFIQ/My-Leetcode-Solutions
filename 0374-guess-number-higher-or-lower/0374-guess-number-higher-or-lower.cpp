/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
class Solution {
public:
    int guessNumber(int n) {
        int result=0; 
        if(guess(n)==0)
         return n;
        if(guess(n)==1)
         return 1;
        else{     
        long long left = 1;
        long long right = n;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(guess(mid)==0)
             {result= mid;break;}
            else if(guess(mid)==1)
             left=mid+1;
            else
             right=mid-1;  
        }           
     }   
     return result;
        
    }

        
};