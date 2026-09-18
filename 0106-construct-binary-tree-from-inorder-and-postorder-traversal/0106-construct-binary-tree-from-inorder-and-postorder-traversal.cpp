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
class Solution {
public:
    int preIndex;

    TreeNode* buildhelper(int left, int right,
                          vector<int>& postorder,
                          vector<int>& inorder)
    {
        if (left > right)
            return nullptr;

        int currentval = postorder[preIndex];
        preIndex--;

        TreeNode* root = new TreeNode(currentval);

        auto it = find(inorder.begin(), inorder.end(), currentval);
        int index = it - inorder.begin();
        root->right = buildhelper(index + 1, right, postorder, inorder);
        root->left = buildhelper(left, index - 1, postorder, inorder);

        

        return root;
    }

    TreeNode* buildTree( vector<int>& inorder,vector<int>& postorder) {
        preIndex = postorder.size()-1;

        return buildhelper(0, inorder.size() - 1, postorder, inorder);
    }
};