/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //iterative method

        while(root!=NULL){
            if(root->val<p->val && root->val<q->val){
                root=root->right;
            }
            else if(root->val>p->val && root->val>q->val){
                root=root->left;
            }
            else{
                break;
            }
        }
        return root;


        //recursive method

        // if(root==NULL){
        //     return NULL;
        // }
        // if(root->val<p->val && root->val<q->val){
        //     return lowestCommonAncestor(root->right,p,q);
        // }
        // if(root->val>p->val && root->val>q->val){
        //     return lowestCommonAncestor(root->left,p,q);
        // }
        // return root;
    }
};
