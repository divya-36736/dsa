/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int level(TreeNode* root, int val, int l){
        if(!root) return 0;
        if(root->val == val) return l;

        int left = level(root->left, val, l+1);
        if(left != 0) return left;

        return level(root->right, val, l+1);
    }

    bool isSiblings(TreeNode* root, int x, int y){
        if(!root) return false;
        if(root->left && root->right){
            if((root->left->val == x && root->right->val == y) || (root->right->val == x && root->left->val == y)){
                return true;
            }
        }
        return isSiblings(root->left, x, y) || isSiblings(root->right, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return level(root, x, 0) == level(root, y, 0) && !isSiblings(root, x, y); 
    }
};