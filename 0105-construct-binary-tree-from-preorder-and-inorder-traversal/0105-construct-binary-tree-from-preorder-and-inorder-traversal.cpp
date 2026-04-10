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
    TreeNode*build(vector<int>&preorder, int preSt, int preEnd, vector<int>&inorder, int inst, int inEnd, map<int, int>&m){
        if(preSt > preEnd || inst>inEnd) return NULL;

        //construct root
        TreeNode* root = new TreeNode(preorder[preSt]);
        //root find in inorder
        int inroot = m[root->val];
        //now split according numleft
        int numleft = inroot - inst;

        root->left = build(preorder, preSt+1, preSt+numleft, inorder, inst, inroot-1, m);
        root->right = build(preorder, preSt+numleft+1, preEnd, inorder, inroot+1, inEnd, m);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>m;
        int n = preorder.size();

        for(int i = 0; i<n; i++){
            m[inorder[i]] = i;
        }

        return build(preorder, 0, n-1, inorder, 0, n-1, m);
    }
};