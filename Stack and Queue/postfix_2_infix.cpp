//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        for (int i=0;i<exp.length();i++)
        {
            string c=string(1, exp[i]);
            if(isalnum(exp[i]))
                st.push(c);
            else{
                string top1=move(st.top());
                st.pop();
                string top2=move(st.top());
                st.pop();
                st.push("(" + std::move(top2) + c + std::move(top1) + ")");
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
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends