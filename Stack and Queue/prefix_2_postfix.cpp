//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string>st;
        for(int i=pre_exp.length()-1;i>=0;i--)
        {
            string c=string (1, pre_exp[i]);
            if(isalnum(pre_exp[i]))
             st.push(c);
            else{
            string top1 =move(st.top());
            st.pop();
            string top2 =move(st.top());
            st.pop();
            st.push( move(top1) + move(top2)+c );
            } 
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends