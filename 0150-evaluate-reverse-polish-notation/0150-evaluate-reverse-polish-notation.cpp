class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i=0;
        while(i<tokens.size()){
            int ans=0;
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int secoperand= st.top();
                st.pop();
                int firstoperand= st.top();
                st.pop();
                if(tokens[i]=="+")
                    ans=firstoperand+secoperand;
                if(tokens[i]=="-")
                    ans=firstoperand-secoperand;
                if(tokens[i]=="*")
                    ans=firstoperand*secoperand;
                if(tokens[i]=="/")
                    ans=firstoperand/secoperand;
                st.push(ans);
            }
            else {
                int x = stoi(tokens[i]);
                st.push(x);
            }
            i++;
        }
        return st.top();
    }
};