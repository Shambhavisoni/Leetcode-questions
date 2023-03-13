class Solution {
public:
    void helper(TreeNode* root,int sum, int &res){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            sum =(sum*2)+root->val;
            res+=sum;
            return;
        }
        else{
            sum=(sum*2)+root->val;
        }
        helper(root->left,sum,res);
        helper(root->right,sum,res);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        int res=0;
        helper(root,sum,res);
        return res;
    }
};
