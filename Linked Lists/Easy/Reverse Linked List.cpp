class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* h1=reverseList(head->next);
        ListNode* t=h1;
        while(t->next!=NULL)
            t=t->next;
        t->next=head;
        head->next=NULL;
        return h1;
    }
};
