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
    void preorder(TreeNode* root, vector<TreeNode*>&pre){
        if(root){
            pre.push_back(root);
            preorder(root->left, pre);
            preorder(root->right, pre);
        }
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*>pre;
        preorder(root, pre);
        TreeNode* temp = root;
        int n = pre.size();
        temp->left = NULL;
        for(int i =1; i<n; i++){
            temp->right = pre[i];
            temp = temp->right;
            temp->left = NULL;
        }
    }
};