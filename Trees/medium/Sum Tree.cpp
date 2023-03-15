// Should return true if tree is Sum Tree, else false
// class Solution
// {
//     public:
//     pair<bool,int> helper(Node* root){
//         if(root==NULL){
//             pair<bool,int> p=make_pair(true,0);
//             return p;
//         }
//         if(root->left==NULL && root->right==NULL){
//             pair<bool,int> p=make_pair(true,root->data);
//             return p;
//         }
//         pair<bool,int> l=helper(root->left);
//         pair<bool,int> r=helper(root->right);
        
//         bool cond1=l.first;
//         bool cond2=r.first;
//         bool cond3=l.second+r.second==root->data;
        
//         pair<bool,int> p;
//         if(cond1 && cond2 && cond3){
//             p.first=true;
//             p.second=2*(root->data);
//         }
//         else{
//             p.first=false;
//         }
//         return p;
//     }
//     bool isSumTree(Node* root)
//     {
//          // Your code here
//          pair<bool,int> p=helper(root);
//          return p.first;
//     }
// };
class Solution
{
    int sum(Node* root){
        if(root==NULL){
            return 0;
        }
        return sum(root->left)+sum(root->right)+root->data;
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL || (root->left==NULL && root->right==NULL)){
             return true;
         }
         int ls=sum(root->left);
         int rs=sum(root->right);
         
         if(isSumTree(root->left) && isSumTree(root->right) && ls+rs==root->data){
             return true;
         }
         else{
             return false;
         }
    }
};
