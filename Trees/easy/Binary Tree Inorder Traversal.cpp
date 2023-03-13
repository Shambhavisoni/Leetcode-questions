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


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */
// class Solution {
//   public:
//     // Function to return a list containing the inorder traversal of the tree.
//     void inOrder1(Node* root, vector<int>& v){
//         if(root == NULL){
//             return ;
//         }
//         inOrder1(root -> left, v);
//         v.push_back(root -> data);
//         inOrder1(root -> right, v);
//     }
//     vector<int> inOrder(Node* root) {
//         // Your code here
//         vector<int> v;
//         inOrder1(root, v);
//         return v;
//     }
// };

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> v;
        stack<Node*> s;
        Node* curr = root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr= curr->left;
            }
            curr = s.top();
            s.pop();
            v.push_back(curr->data);
            curr = curr ->right;
        }
        return v;
    }
};

//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
