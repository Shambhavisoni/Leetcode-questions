/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,int &c,int k,int &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,c,k,ans);
        c++;
        if(c==k){
            ans=root->val;
            return;
        }
        inorder(root->right,c,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0,ans;
        inorder(root,c,k,ans);
        return ans;
    }
};
