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
    TreeNode* minVal(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        TreeNode* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //1 child
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            //2 children
            if(root->left!=NULL && root->right!=NULL){
            //     BinaryTreeNode<int>* minimum=minVal(root->right);
            //     int m=minimum->data;
            //     root->data=m;     
            //     root->right=deleteNode(root->right, m);
            // return root;

                int mini=minVal(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};

/*BinaryTreeNode<int>* minVal(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* temp=root;
    while(temp->left!=NULL) {
        temp=temp->left;
    }
    return temp;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    //base case
    if(root==NULL) return NULL;

    if(root->data == key) {
        // 0 child/ subtree 
        if(root->right==NULL && root->left==NULL) {
            delete root;
            return NULL;
        }

        // 1 left child/ subtree 
        if(root->right==NULL && root->left!=NULL) {
            BinaryTreeNode<int>* temp=root->left;
            delete root;
            return temp;
        }

        // 1 right child/ subtree 
        if(root->left==NULL && root->right!=NULL) {
            BinaryTreeNode<int>* temp=root->right; 
            delete root;
            return temp;
        }

        // 2 children/ subtrees  
        if(root->right!=NULL && root->left!=NULL) {
                BinaryTreeNode<int>* minimum=minVal(root->right);
                int m=minimum->data;
                root->data=m;     
                root->right=deleteNode(root->right, m);
            return root;
        }

        else if(key > root->data) {
            root->right=deleteNode(root->right, key);
            return root;
        }

        else {
            root->left=deleteNode(root->left, key);
            return root;
        }
    }
    return root;
}
*/
