/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<int,int> map;
        unordered_map<Node*,Node*> m2;
        int i=0;
        Node* temp=head;
        while(temp!=NULL){
            map[i]=temp->val;
            i++;
            temp=temp->next;
        }
        int j=0;
        Node* head2=new Node(0);
        Node* curr=head2;
        while(j!=i){
            curr->next=new Node(map[j]);
            curr=curr->next;
            j++;
        }
        m2.clear();
        temp=head;
        curr=head2->next;
        while(temp!=NULL){
            m2[temp]=curr;
            temp=temp->next;
            curr=curr->next;
        }
        temp=head;
        curr=head2->next;
        while(temp!=NULL){
            if(temp->random!=NULL){
                Node* a=temp->random;
                curr->random=m2[a];
            }
            temp=temp->next;
            curr=curr->next;
            // i++;
            // it++;
        }
        return head2->next;
    }
};
