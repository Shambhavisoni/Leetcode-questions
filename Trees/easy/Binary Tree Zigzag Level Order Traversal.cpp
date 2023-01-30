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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        bool flag=true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(flag){
                    ans[i]=temp->val;
                }
                else{
                    ans[size-i-1]=temp->val;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            flag=!flag;
            res.push_back(ans);
        }
        return res;
    }
};
