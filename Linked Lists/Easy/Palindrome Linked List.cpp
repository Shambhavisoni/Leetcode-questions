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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        int l=len(head);
        ListNode* temp=head;
        stack<int> s;
        if(l%2==0){
            int c=0;
            while(temp!=NULL){
                if(c<l/2){
                    s.push(temp->val);
                }
                else if(!s.empty() && s.top()==temp->val){
                    s.pop();
                }
                // else{
                //     s.push(temp->val);
                // }
                temp=temp->next;
                c++;
            }
        }
        else{
            int c=0;
            while(temp!=NULL){
                if(!s.empty() && s.top()==temp->val){
                    s.pop();
                }
                else{
                    s.push(temp->val);
                }
                temp=temp->next;
                c++;
                if(temp!=NULL && c==l/2){
                    temp=temp->next;
                    c++;
                }
            }
        }
        return s.empty();
    }
};
