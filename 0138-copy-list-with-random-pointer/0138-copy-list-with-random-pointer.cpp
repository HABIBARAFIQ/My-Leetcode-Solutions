/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(head==nullptr)return nullptr;
      Node* temp=head;  
      Node* dpcopy=nullptr;
      Node* temp1=dpcopy;
      unordered_map<Node*, Node*> mp;
      while(temp!=nullptr)
      {
        Node* newnode = new Node(temp->val);
        if(dpcopy==nullptr) {
            dpcopy=newnode;
            temp1=dpcopy;
        }
        else{
            temp1->next=newnode;
            temp1=temp1->next;
        }
        // temp1->next=temp->next;
        mp[temp]=newnode;
        temp=temp->next;
      }
      temp=head;
      temp1=dpcopy;

      while(temp!=nullptr)
      {
        // Node* newnode = new Node(temp->val);
        // newnode->next = temp->next;
        temp1->random=mp[temp->random];
        temp=temp->next;
        temp1=temp1->next; 
      }
      return  dpcopy; 
    }
};