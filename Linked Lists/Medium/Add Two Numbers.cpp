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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d=new ListNode();
        ListNode* t=d;
        int c=0;
        while(l1!=NULL || l2!=NULL || c!=0){
            int s=0;
            if(l1!=NULL){
                s+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                s+=l2->val;
                l2=l2->next;
            }
            // if(c!=0){
                s+=c;
                c=0;
            // }
            // if(s<9){
            //     ListNode* n=new ListNode(s);
            //     t->next=n;

            // }
            // else{
                ListNode* n=new ListNode(s%10);
                t->next=n;
                c=s/10;
            // }
            t=t->next;
            // if(l1!=NULL){
            //     l1=l1->next;
            // }
            // if(l2!=NULL){
            //     l2=l2->next;
            // }
        }
        return d->next;
    }
};

// class Solution {
// public:
//     int len(ListNode* head){
//         if(head==NULL){
//             return 0;
//         }
//         return len(head->next)+1;
//     }
//     ListNode* reverse(ListNode* head){
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         ListNode* h1=reverse(head->next);
//         ListNode* t=h1;
//         while(t->next!=NULL){
//             t=t->next;
//         }
//         t->next=head;
//         head->next=NULL;
//         return h1;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* t1=reverse(l1);
//         ListNode* t2=reverse(l2);
//         int num1=0,num2=0;
//         while(t1!=NULL){
//             num1=num1*10+(t1->val);
//             t1=t1->next;
//         }
//         while(t2!=NULL){
//             num2=num2*10+(t2->val);
//             t2=t2->next;
//         }
//         int sum=num1+num2;
//         ListNode* head=new ListNode(0);
//         if(sum==0){
//             return head;
//         }
//         ListNode* curr=head;
//         while(sum>0){
//             int y=sum%10;
//             curr->next=new ListNode(y);
//             curr=curr->next;
//             sum/=10;
//         }
//         return head->next;
       
//     }
// };
