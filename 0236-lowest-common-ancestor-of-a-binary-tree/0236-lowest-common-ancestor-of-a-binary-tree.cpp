/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr )return nullptr;
        if(root == p|| root == q)return root;
        TreeNode* leftca = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightca = lowestCommonAncestor(root->right,p,q);
        if (leftca != nullptr && rightca != nullptr)return root;
        if(leftca != nullptr )return leftca;
        return rightca;
    }
};