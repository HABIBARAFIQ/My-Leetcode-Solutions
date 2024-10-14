//{ Driver Code Starts
// Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

// Floor value of any number is the greatest Integer which is less than or equal to that number
// Input: n = 5
// Output: 2
// Input: n = 4
// Output: 2
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long left=1;
        long long right=n;
        while(left<=right)
        {
            long long mid=(right+left)/2;
            long long square=mid*mid;
            if(square==n)
             return mid;
            else if(square>n)
             right=mid-1;
            else 
             left=mid+1;  
        }
        return left-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends