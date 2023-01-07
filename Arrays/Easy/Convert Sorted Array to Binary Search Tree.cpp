/*Sorted Array to Balanced BST By Finding The middle element

*The idea is to find the middle element of the array and make it the root of the tree, then perform the same operation on the left subarray for the root’s left child and the same operation on the right subarray for the root’s right child.*

Follow the steps mentioned below to implement the approach:

* Set The middle element of the array as root.
* Recursively do the same for the left half and right half.
* Get the middle of the left half and make it the left child of the root created in step 1.
* Get the middle of the right half and make it the right child of the root created in step 1.
* Print the preorder of the tree.

Time Complexity: O(N) 
Auxiliary Space: O(H) ~= O(log(N)), for recursive stack space where H is the height of the tree.*/

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
    TreeNode* helper(vector<int>& nums,int si,int ei){
        if(si>ei){
            return NULL;
        }
        int mid=(si+ei)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=helper(nums,si,mid-1);
        root->right=helper(nums,mid+1,ei);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
