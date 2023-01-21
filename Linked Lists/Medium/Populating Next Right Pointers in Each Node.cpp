/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        if(root->left==NULL){
            root->next=NULL;
            return root;
        }
        Node* r=root;
        r->next=NULL;
        queue<Node*> q;
        q.push(r);
        Node* prev=NULL;
        int c=2;
        while(!q.empty()){
            Node* t=q.front();
            q.pop();
            if(t->left!=NULL){
                t->left->next=t->right;
                q.push(t->left);
                q.push(t->right);
                if(prev!=NULL){
                    prev->next=t->left;
                    prev=NULL;
                }
                if(c>q.size()){
                    prev=t->right;
                }
                if(c==q.size()){
                    t->right->next=NULL;
                    c*=2;
                }
            }
        }
        r->next=NULL;
        return root;
    }
};
