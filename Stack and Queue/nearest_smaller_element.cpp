vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> prev_smaller;
    prev_smaller.resize(n,-1);
    stack<int>st;
    st.push(A[0]);
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty())
        {
             prev_smaller[i]=st.top();
        }
        st.push(A[i]);
    }
    return prev_smaller;
}