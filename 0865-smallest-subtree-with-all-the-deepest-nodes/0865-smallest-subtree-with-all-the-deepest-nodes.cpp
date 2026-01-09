class Solution {
public:
    int maxDepth = 0;
    vector<TreeNode*> deepest;

    // Step 1: find maximum depth
    void findDepth(TreeNode* root, int depth) {
        if (!root) return;

        maxDepth = max(maxDepth, depth);
        findDepth(root->left, depth + 1);
        findDepth(root->right, depth + 1);
    }

    // Step 2: collect deepest nodes
    void collectDeepest(TreeNode* root, int depth) {
        if (!root) return;

        if (depth == maxDepth) {
            deepest.push_back(root);
        }

        collectDeepest(root->left, depth + 1);
        collectDeepest(root->right, depth + 1);
    }

    // Step 3: LCA of two nodes
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;

        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return NULL;

        // Step 1
        findDepth(root, 0);

        // Step 2
        collectDeepest(root, 0);

        // Step 3
        TreeNode* ans = deepest[0];
        for (int i = 1; i < deepest.size(); i++) {
            ans = lca(root, ans, deepest[i]);
        }

        return ans;
    }
};
