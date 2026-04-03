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
    void dfs(TreeNode* root, int currsum, int targetSum, vector<int>&path, vector<vector<int>>&res){

        if(!root) return;
        
        currsum += root->val;
        path.push_back(root->val);

        if(!root->left && !root->right && currsum == targetSum){
            res.push_back(path);
        }
        dfs(root->left, currsum, targetSum, path, res);
        dfs(root->right,currsum, targetSum, path, res);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>path;
        int currsum = 0;
        dfs(root, 0, targetSum, path, res);
        return res;
    }
};