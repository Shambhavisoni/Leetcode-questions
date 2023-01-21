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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* he=NULL;
        ListNode* te=NULL;
        ListNode* ho=NULL;
        ListNode* to=NULL;
        ListNode* t=head;
        int c=1;
        while(t!=NULL){
            if(c%2!=0){
                if(ho==NULL){
                    ho=t;
                    to=t;
                }
                else{
                    to->next=t;
                    to=t;
                }
            }
            else{
                if(he==NULL){
                    he=t;
                    te=t;
                }
                else{
                    te->next=t;
                    te=t;
                }
            }
            t=t->next;
            c++;
        }
        if(te!=NULL){
            te->next=NULL;
        }
        if(ho==NULL){
            return he;
        }        
        to->next=he;
        return ho;
    }
};
