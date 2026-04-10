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
    TreeNode* build(vector<int>&inorder, int inst, int inEnd, vector<int>&postorder, int postSt, int postEnd, map<int, int>&m){
        if(inst>inEnd || postSt > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inroot = m[root->val];
        int numleft = inroot-inst;

        root->left = build(inorder, inst, inroot - 1,
                           postorder, postSt, postSt + numleft - 1, m);

        root->right = build(inorder, inroot + 1, inEnd,
                            postorder, postSt + numleft, postEnd - 1, m);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>m;

        int n = inorder.size();
        for(int i = 0; i<n; i++){
            m[inorder[i]] = i;
        }

        return build(inorder, 0, n-1, postorder,0, n-1, m);
    }
};