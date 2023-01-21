class Solution {
public:
    int len(ListNode* head){
        if(head==NULL){
            return 0;
        }
        return len(head->next)+1;
    }
    int getDecimalValue(ListNode* head) {
        int n=len(head);
        ListNode* temp=head;
        int num=0;
        while(temp!=NULL){
            num+=(temp->val)*pow(2,n-1);
            n--;
            temp=temp->next;
        }
        return num;
    }
};
