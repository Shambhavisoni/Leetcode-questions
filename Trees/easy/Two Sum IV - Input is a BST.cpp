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
    void inorder(TreeNode* root, vector<int> &nodes){
        if(root==NULL){
            return;
        }
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root,nodes);
        int i=0, j=nodes.size()-1;
        while(i<j){
            if(nodes[i]+nodes[j]==k){
                return true;
            }
            else if(nodes[i]+nodes[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
