/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return root;
        queue<Node* >Q;
        Node* prev=nullptr;
        Node* now=nullptr;
        Q.push(root);
        int size=Q.size();
        while(!Q.empty()){
            if(Q.front()->left==nullptr && Q.front()->right==nullptr)
                {
                    Q.pop();
                    size--;
                    continue;
                    
                    
                }
                
            while(size>0)
            {
                if(Q.front()->left==nullptr && Q.front()->right==nullptr)
                {
                    Q.pop();
                    size--;
                    continue;
                    
                    
                }
                Node* current = Q.front();
                // if()
                if(current->left!=nullptr){
                    Q.push(current->left);
                    
                }
                if(current->right!=nullptr){
                    Q.push(current->right);
                   
                }
                if(current->left!=nullptr)
                    now=current->left;
                else if(current->left==nullptr&&current->right!=nullptr)
                    now=current->right;    
                
                if(prev!=nullptr){
                    if(prev!=now)
                        prev->next=now;
                    if(current->left!=nullptr && current->right!=nullptr)
                        now->next=current->right;
                }
                if(prev==nullptr && current->left!=nullptr) current->left->next=current->right;
                if(current->right!=nullptr)
                    prev=current->right;
                else prev=current->left;
                
                size--;
                Q.pop();
            }
            now=nullptr;
            prev=nullptr;
            size=Q.size();
            

        }
        return root;
    }
};