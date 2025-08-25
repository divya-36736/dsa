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
    int count(TreeNode* root){
        if(!root){
            return 0;
        }

        return 1+count(root->left) + count(root->right);
    }
    bool CBT(TreeNode* root, int idx, int totcount){
        if(!root) return 1;

        if(totcount <= idx) return 0;

        return CBT(root->left, 2*idx+1, totcount) && 
        CBT(root->right, 2*idx+2, totcount);
    }
    bool isCompleteTree(TreeNode* root) {
        int totcount = count(root);
        return CBT(root, 0, totcount);
        
    }
};