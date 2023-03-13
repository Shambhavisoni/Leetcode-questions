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
    bool isBST(TreeNode* root,int min,int max){
        if(root==NULL){
            return true;
        }
        if(root->val>min && root->val<max){
            bool left=isBST(root->left,min,root->val);
            bool right=isBST(root->right,root->val,max);
            return left && right;
        }
        else
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,INT_MIN,INT_MAX);
    }
};


// void inorder(TreeNode* root,vector<int>& v){
//         if(root==NULL){
//             return;
//         }
//         inorder(root->left,v);
//         v.push_back(root->val);
//         inorder(root->right,v);
//     }
//     bool isValidBST(TreeNode* root) {
//         vector<int> v;
//         inorder(root,v);
//         for(int i=0;i<v.size()-1;i++){
//             if(v[i]>=v[i+1]){
//                 return false;
//             }
//         }
//         return true;
//     }
