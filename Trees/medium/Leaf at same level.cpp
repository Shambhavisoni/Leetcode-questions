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
