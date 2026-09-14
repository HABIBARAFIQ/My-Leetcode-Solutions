/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        unordered_map<int, int> freq;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            freq[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        ListNode* joint_node;
        ListNode* prevnode=head;
        ListNode* nextnode;
        while(temp!=nullptr){
            // prevnode=temp;
            nextnode=temp->next;
            if(freq[temp->val]>1)
            {               
                // joint_node=temp->next;
                prevnode->next=nullptr;
                if(prevnode!=temp)temp->next=nullptr;
                // if(prevnode!=head){
                prevnode->next=nextnode;
                // }
                // freq[temp->value]--;
                if(freq[head->val]>1)head=nextnode;
            }
            else prevnode=temp;            
            temp=nextnode;
        }
        return head;
    }
};