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
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int lh = dfs(root->left);
        int rh = dfs(root->right);
        int lcnt = 0;
        int rcnt = 0;
        if(root->left && root->left->val == root->val) lcnt = lh+1;
        if(root->right && root->right->val == root->val) rcnt = rh+1;

        ans = max(ans, lcnt+rcnt);
        return max(lcnt, rcnt);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};