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
// helper(left, right)

//     base case

//     preorder থেকে current root value নাও
//     preIndex বাড়াও

//     node create করো

//     inorder-এ node-এর position বের করো

//     node->left = recursion
//     node->right = recursion

//     return node
class Solution {
public:
    int preIndex;

    TreeNode* buildhelper(int left, int right,vector<int>& preorder,vector<int>& inorder){
        if (left > right)
            return nullptr;
        int currentval = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(currentval);
        auto it = find(inorder.begin(), inorder.end(), currentval);
        int index = it - inorder.begin();
        root->left = buildhelper(left, index - 1, preorder, inorder);
        root->right = buildhelper(index + 1, right, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex = 0;

        return buildhelper(0, inorder.size() - 1, preorder, inorder);
    }
};