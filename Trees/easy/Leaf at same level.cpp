// class Solution{
//   public:
//     /*You are required to complete this method*/
//     bool helper(Node *root, int ans,int lvl){
//         if(root==NULL){
//             return true;
//         }
//         if(root->left==NULL && root->right==NULL){
//             if(ans!=lvl){
//                 return false;
//             }
//             return true;
//         }
//         bool l=helper(root->left,ans,lvl+1);
//         bool r=helper(root->right,ans,lvl+1);
//         return l && r;
//     }
//     bool check(Node *root)
//     {
//         //Your code here
//         if(root==NULL){
//             return true;
//         }
//         Node* temp=root;
//         int ans=0;
//         while(!(temp->left==NULL && temp->right==NULL)){
//             if(temp->left){
//                 temp=temp->left;
//             }
//             else{
//                 temp=temp->right;
//             }
//             ans++;
//         }
//         return helper(root,ans,0);
//     }
// };
class Solution{
  public:
    /*You are required to complete this method*/
    bool helper(Node *root, int &ans,int lvl){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            if(ans==-1){
                ans=lvl;
                return true;
            }
            return (ans==lvl);
        }
        bool l=helper(root->left,ans,lvl+1);
        bool r=helper(root->right,ans,lvl+1);
        return l && r;
    }
    bool check(Node *root)
    {
        //Your code here
        int ans=-1;
        return helper(root,ans,0);
    }
};
