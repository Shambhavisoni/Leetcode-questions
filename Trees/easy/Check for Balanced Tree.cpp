/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// class Solution{
//     public:
//     //Function to check whether a binary tree is balanced or not.
//     int height(Node* root){
//         if(root==NULL){
//             return 0;
//         }
//         return max(height(root->left),height(root->right))+1;
//     }
//     bool isBalanced(Node *root)
//     {
//         //  Your Code here
//         if(root==NULL){
//             return true;
//         }
//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);
//         bool h=abs(height(root->left)-height(root->right))<=1;
//         return left&&right&&h;
//     }
// };
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int> helper(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        pair<bool,int> left=helper(root->left);
        pair<bool,int> right=helper(root->right);
        
        bool lB=left.first;
        bool rB=right.first;
        int lH=left.second;
        int rH=right.second;
        bool h=abs(left.second-right.second)<=1;
        
        pair<bool,int> p=make_pair(lB&&rB&&h,max(lH,rH)+1);
        return p;
        
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        pair<bool,int> p=helper(root);
        return p.first;
    }
};
