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
    int sum;
    deque<int> q;
    int findsum(int sum,TreeNode* root,deque<int> &q)
    {
        if(root->left==nullptr&&root->right==nullptr)
        {
            q.push_back(root->val);
            deque<int> temp = q;
            int num = 0;

            while (!temp.empty())
            {
                num = num * 10 + temp.front();
                temp.pop_front();
            }
            // if (sum == num) {
            //     return sum;
            // }
            q.pop_back();
            return sum + num;
        }
        q.push_back(root->val);
        if(root->left!=nullptr)sum = findsum(sum,root->left,q);
        if(root->right!=nullptr)sum = findsum(sum,root->right,q);
        q.pop_back();
        return sum;
    }
    // 4+9
    int sumNumbers(TreeNode* root) {
        sum=0;
        if(root==nullptr)return 0;
        int s=findsum(sum,root,q);
        return s;
        
    }
};