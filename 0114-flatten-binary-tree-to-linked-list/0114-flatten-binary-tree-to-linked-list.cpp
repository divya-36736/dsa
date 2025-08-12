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
    TreeNode* NR = NULL; //nextRight or last visited node
    void flatten(TreeNode* root) {
        //we do in this preoder reverse traversal
        if(root == NULL) return ;

        flatten(root->right);//in reveser order 1st we go in right side
        flatten(root->left); //ans then left side

        root->left = NULL; //left ko NULL assign krdo
        root->right = NR; //root ke right ko next right krdo
        NR = root; //next right root now
    } 
};