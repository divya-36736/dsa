class Solution {
public:
    // helper function: returns {depth, subtree_root}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        // base case
        if (root == NULL) {
            return {0, NULL};
        }

        // recurse on left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // if both sides have same depth, current node is answer
        if (left.first == right.first) {
            return {left.first + 1, root};
        }

        // if left subtree is deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // if right subtree is deeper
        return {right.first + 1, right.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
