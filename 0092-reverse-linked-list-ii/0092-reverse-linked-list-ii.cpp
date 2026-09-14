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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr )return nullptr;
        if(head->next==nullptr)return head;
        if((left==1&&right==1)||left==right)return head;
        int pos=1;
        ListNode* temp=head;
        ListNode* prev=head;
        while(pos!=left&&temp!=nullptr)
        {
            pos++;
            prev=temp; 
            temp=temp->next;
        }
        ListNode* revlast=temp;
        while(pos!=right&&temp!=nullptr)
        {
            pos++;
            temp=temp->next;
        }
        if(left!=1)prev->next=nullptr;
        ListNode* revfirst=temp;
        ListNode* revtemp=revlast;
        ListNode* nextnode;
        ListNode* prevnode;
        while(revtemp!=revfirst){
            if(revtemp==revlast){
                prevnode = revtemp;
                nextnode=revtemp->next;
            }
            else{
                if(prevnode->next==revtemp->next)
                    prevnode->next=nullptr;
                nextnode=revtemp->next;
                revtemp->next=nullptr;
                revtemp->next=prevnode;
                prevnode=revtemp;
            }
            revtemp=nextnode;
        }
        nextnode=revtemp->next;
        revtemp->next=nullptr;
        revtemp->next=prevnode;
        prev->next=revtemp;
        revlast->next=nextnode;
        if(left==1)head=revtemp;
        return head;

    }
};