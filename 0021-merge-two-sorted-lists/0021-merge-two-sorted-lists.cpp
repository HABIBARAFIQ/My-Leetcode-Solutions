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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr&&list2==nullptr)return nullptr;
        if(list1==nullptr&&list2!=nullptr)return list2;
        if(list1!=nullptr&&list2==nullptr)return list1;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* temp=nullptr;
        ListNode* temphead;
        while(temp1!=nullptr&&temp2!=nullptr)
        {
            ListNode* merge;
            if(temp1->val<=temp2->val)
            {
                merge = new ListNode(temp1->val);
                if(temp==nullptr) {                   
                    temp=merge;
                    temphead=temp;
                }
                else{
                      temp->next=merge; 
                      temp=temp->next;
                    }
                
                temp1=temp1->next;

            }
            else{
                merge = new ListNode(temp2->val);
                if(temp==nullptr) {                    
                    temp=merge;
                    temphead=temp;
                }
                else{
                      temp->next=merge; 
                      temp=temp->next;
                    }
                temp2=temp2->next;
            }
        }
            while(temp1!=nullptr)
            {
                ListNode* merge;
                merge = new ListNode(temp1->val);
                temp->next=merge; 
                temp=temp->next;
                temp1=temp1->next;
            }
            while(temp2!=nullptr)
            {
                ListNode* merge;
                merge = new ListNode(temp2->val);
                temp->next=merge; 
                temp=temp->next;
                temp2=temp2->next;
            }
            return temphead;
            // if(temp==nullptr) temp=merge;
            // else temp=temp->next;
        
    }
};