/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    // TreeNode* root;
    queue<TreeNode* > st;
    void initialization(queue<TreeNode* > &st,TreeNode* root)
    {
        if(root==nullptr)
            return ;
        initialization(st,root->left);
        st.push(root);
        initialization(st,root->right);    
    }
    BSTIterator(TreeNode* root) {
        // this->root = root;
        initialization(st,root);
    }
    
    // 3 7 9 15 20
    int next() {
        TreeNode* next_add = st.front();
        int next_val = next_add->val;
        st.pop();
        return next_val;
    }
    
    bool hasNext() {
        if(!st.empty())
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */