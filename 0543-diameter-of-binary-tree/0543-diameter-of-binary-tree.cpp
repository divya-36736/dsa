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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans, lh+rh); // add this for optial solution
        return max(lh, rh) + 1;
    };


    int diameterOfBinaryTree(TreeNode* root) {
        // if(root == NULL) return 0;
        // int leftdia = diameterOfBinaryTree(root->left);
        // int rightdia = diameterOfBinaryTree(root->right);
        // int currdia = height(root->left) + height(root->right);
        // return max(max(leftdia, rightdia), currdia);

        //optimal 
        height(root);
        return ans;
    }
};