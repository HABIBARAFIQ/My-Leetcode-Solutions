//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int findFirstOccurrence(int Arr[], int N, int X) {
    int low = 0, high = N - 1, firstOccurrence = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (Arr[mid] == X) {
            firstOccurrence = mid;
            high = mid - 1;  // Move to the left half to find the first occurrence
        } else if (Arr[mid] > X) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return firstOccurrence;
}

int findLastOccurrence(int Arr[], int N, int X) {
    int low = 0, high = N - 1, lastOccurrence = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (Arr[mid] == X) {
            lastOccurrence = mid;
            low = mid + 1;  // Move to the right half to find the last occurrence
        } else if (Arr[mid] > X) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return lastOccurrence;
}	
	int count(int arr[], int n, int x) {
	    // code here
	int first = findFirstOccurrence(arr, n, x);
    if (first == -1) {
        // X is not present in the array
        return 0;
    }
    
    int last = findLastOccurrence(arr, n, x);
    
    return (last - first + 1); 
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends