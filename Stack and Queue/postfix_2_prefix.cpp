//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>st;
        for(int i=0;i<post_exp.length();i++)
        {
            string c=string (1, post_exp[i]);
            if(isalnum(post_exp[i]))
             st.push(c);
            else{
            string top1 =move(st.top());
            st.pop();
            string top2 =move(st.top());
            st.pop();
            st.push(c+ move(top2) + move(top1) );
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends