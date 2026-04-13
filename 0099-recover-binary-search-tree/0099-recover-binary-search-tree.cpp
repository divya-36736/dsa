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
    void inorderStore(TreeNode* root, vector<int>&vals){
        if(!root) return;
        inorderStore(root->left, vals);
        vals.push_back(root->val);
        inorderStore(root->right, vals);
    }
    void inorderFix(TreeNode* root, vector<int>&vals, int &i){
        if(!root) return;
        inorderFix(root->left, vals, i);
        root->val = vals[i++];
        inorderFix(root->right, vals, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>vals;
        inorderStore(root, vals);
        sort(vals.begin(), vals.end());
        int i = 0;
        inorderFix(root, vals, i);
    }
};