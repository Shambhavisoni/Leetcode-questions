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
    ListNode* mid(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergeLL(ListNode* h1,ListNode* h2){
        if(h1==NULL){
            return h2;
        }
        if(h2==NULL){
            return h1;
        }
        ListNode* h=NULL;
        ListNode* t=NULL;
        while(h1!=NULL && h2!=NULL){
            if(h1->val<h2->val && h==NULL){
                h=h1;
                t=h1;
                h1=h1->next;
            }
            else if(h1->val<h2->val && h!=NULL){
                t->next=h1;
                t=h1;
                h1=h1->next;
            }
            else if(h1->val>=h2->val && h==NULL){
                h=h2;
                t=h2;
                h2=h2->next;
            }
            else if(h1->val>=h2->val && h!=NULL){
                t->next=h2;
                t=h2;
                h2=h2->next;
            }
        }
        if(h1==NULL){
            t->next=h2;
        }
        else if(h2==NULL){
            t->next=h1;
        }
        return h;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* a=mid(temp);
        ListNode* h2=a->next;
        a->next=NULL;
        ListNode* p1=sortList(head);
        ListNode* p2=sortList(h2);
        ListNode* newH=mergeLL(p1,p2);
        return newH;
    }
};
