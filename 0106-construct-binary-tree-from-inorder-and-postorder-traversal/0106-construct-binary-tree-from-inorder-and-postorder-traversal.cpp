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
    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int,int>&mpp){
        //base case
        if(ps>pe || is>ie){
            return NULL;
        }
        //create root
        TreeNode* root = new TreeNode(postorder[pe]);
        //find value in inorder traversal
        int inRoot = mpp[postorder[pe]];
        int numsLeft = inRoot-is;
        //recursively build left and right sub tree
        root->left = buildTreePostIn(inorder, is, inRoot-1, postorder, ps, ps+numsLeft - 1, mpp);
        root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder,
            ps + numsLeft, pe - 1, mpp);

            return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        //create the map fro store the index
        map<int,int>mpp;
        for(int i = 0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        //call the recursively
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
    }
};