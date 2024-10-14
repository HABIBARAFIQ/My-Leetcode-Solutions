//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long multiply(long long mid, int n, long long m)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return ans;  
        }
        return ans;
    }
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if (m == 1) return 1;
	    long long  left=1;
        long long  right=m;
        while(left<=right)
        {
            long long mid=(left+right)/2;
            long long midPow = multiply(mid, n, m);
            if(midPow==m)
             return mid;
            else if(midPow>m)
             right=mid-1;
            else
             left=mid+1;  
        }
        return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends