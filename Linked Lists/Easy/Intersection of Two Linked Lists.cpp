/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return len(head->next)+1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=len(headA);
        int l2=len(headB);
        int diff=abs(l2-l1);
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int c=0;
        if(l1>l2){
            while(c!=diff){
                temp1=temp1->next;
                c++;
            }
        }
        else{
            while(c!=diff){
                temp2=temp2->next;
                c++;
            }
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
};
