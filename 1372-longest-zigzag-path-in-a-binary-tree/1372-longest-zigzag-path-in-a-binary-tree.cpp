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
    void dfs(TreeNode* root, bool goleft, int len, int &ans){
        if(!root) return;
        ans = max(ans, len);
        if(goleft){
            dfs(root->left, false, len+1, ans);
            //reset if we go in same dir
            dfs(root->right, true, 1, ans);
        }else{
            dfs(root->right, true, len+1, ans);
            dfs(root->left, false, 1, ans);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, true, 0, ans); //goleft
        dfs(root, false, 0, ans); //go right
        return ans;
    }
};