class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge;
        vector<int>nge_new;
        unordered_map<int, int> ngeMap;
        nge_new.resize(nums1.size());
        nge.resize(nums2.size());
        stack<int>st;
        for(int i= nums2.size()-1;i>=0;i--)
        {
            if(st.empty()){
                nge[i]=-1;
            }
            else {
                if(st.top()<nums2[i])
                {   
                    while(!st.empty()&&st.top()<nums2[i]){
                        st.pop();
                    }
                    if(st.empty())
                         nge[i]=-1;
                    else 
                        nge[i]= st.top();                          
                }
                else{
                    nge[i]=st.top();
                }
            }
            st.push(nums2[i]);
            ngeMap[nums2[i]] = nge[i];     
        }
        for (int i = 0; i < nums1.size(); ++i) {
         nge_new[i] = ngeMap[nums1[i]]; 
        }

    return nge_new;

    }
};