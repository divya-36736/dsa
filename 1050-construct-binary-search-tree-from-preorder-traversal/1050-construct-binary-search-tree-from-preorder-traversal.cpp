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
    int idx = 0;  // shared index

    TreeNode* build(vector<int>& preorder, int bound) {
        if (idx == preorder.size() || preorder[idx] > bound) 
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        // Left subtree: values smaller than root->val
        root->left = build(preorder, root->val);
        // Right subtree: values smaller than current bound but > root->val
        root->right = build(preorder, bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};
