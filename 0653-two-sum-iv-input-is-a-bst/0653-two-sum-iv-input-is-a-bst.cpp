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
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inorder(root, vals);

        int l = 0, r = vals.size() - 1;
        while (l < r) {
            int sum = vals[l] + vals[r];
            if (sum == k) return true;
            else if (sum < k) l++;
            else r--;
        }
        return false;
    }
};
