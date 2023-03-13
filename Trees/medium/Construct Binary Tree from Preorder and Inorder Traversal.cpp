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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &preBegin,map<int,int> &m,int inBegin,int inEnd){
        if(preBegin>=preorder.size() || inBegin > inEnd){
            return NULL;
        }
        int elem=preorder[preBegin++];
        TreeNode* root = new TreeNode(elem);
        int pos=m[elem];
        root->left = helper(preorder,inorder,preBegin,m,inBegin,pos-1);
        root->right = helper(preorder,inorder,preBegin,m,pos+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // TreeNode* root=new TreeNode(preorder[0]);
        int preBegin=0;
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* ans = helper(preorder,inorder,preBegin,m,0,inorder.size()-1);
        return ans;
    }
};
