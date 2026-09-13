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

    void dfs(TreeNode* root, long long currSum, int targetsum, unordered_map<long long, int>mp){
        if(root == NULL) return;

        currSum += root->val;

        if(mp.find(currSum - targetsum) != mp.end()){
            ans += mp[currSum - targetsum];
        }
        mp[currSum]++;

        dfs(root->left, currSum, targetsum, mp);
        dfs(root->right, currSum, targetsum, mp);

        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>mp;

        mp[0] = 1;
        dfs(root, 0, targetSum, mp);
        return ans;
    }
};