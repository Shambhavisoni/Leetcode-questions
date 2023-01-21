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
    int len(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return len(head->next)+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        int c=0;
        int pos=len(head)-n;
        ListNode* t=head;
        if(pos==0){
            head=t->next;
            return head;
        }
        while(t!=NULL && c!=pos-1){
            t=t->next;
            c++;
        }
        if(t!=NULL){
            t->next=t->next->next;
        }
        return head;
    }
};
