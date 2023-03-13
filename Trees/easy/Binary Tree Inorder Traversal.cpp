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
    // void in(TreeNode* root,vector<int> &v){
    //     if(root==NULL){
    //         return;
    //     }
    //     in(root->left,v);
    //     v.push_back(root->val);
    //     in(root->right,v);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        // in(root,v);
        // return v;

        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr!=NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* f=s.top();
                s.pop();
                v.push_back(f->val);
                curr=f->right;
            }
        }
        return v;
        // vector<int> v;
        // stack<TreeNode*> s;
        // TreeNode* curr=root;
        // while(curr!=NULL || !s.empty()){
        //     while(curr!=NULL){
        //         s.push(curr);
        //         curr=curr->left;
        //     }
        //     curr=s.top();
        //     s.pop();
        //     v.push_back(curr->val);
        //     curr=curr->right;
        // }
        // return v;
    }
};
