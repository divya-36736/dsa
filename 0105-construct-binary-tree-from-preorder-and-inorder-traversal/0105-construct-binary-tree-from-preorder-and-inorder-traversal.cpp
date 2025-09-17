// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int search(vector<int>inorder, int left, int right, int val){
//         for(int i = left; i<=right; i++){
//             if(inorder[i] == val){
//                 return i;
//             }
//         }
//         return -1;
//     }

//     TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preidx, int left, int right){
//         if(left > right){
//             return NULL;
//         }

//         TreeNode* root = new TreeNode(preorder[preidx]);
        
//         int inidx = search(inorder, left, right, preorder[preidx]);
//         preidx++;
//         root->left = helper(preorder, inorder, preidx, left, inidx-1); //left subtree
//         root->right = helper(preorder, inorder, preidx, inidx+1, right);//right subtree

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int preidx = 0;
//         return helper(preorder, inorder, preidx, 0, inorder.size()-1);
       
//     }
// };

class Solution {
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preidx,
                     int left, int right, unordered_map<int,int>& mpp) {
        if (left > right) return NULL;

        // root node = current preorder element
        TreeNode* root = new TreeNode(preorder[preidx]);

        // find root index in inorder using map
        int inidx = mpp[preorder[preidx]];
        preidx++;

        // recursively build left and right
        root->left = helper(preorder, inorder, preidx, left, inidx - 1, mpp);
        root->right = helper(preorder, inorder, preidx, inidx + 1, right, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;

        // build map of inorder value -> index
        unordered_map<int,int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return helper(preorder, inorder, preidx, 0, inorder.size() - 1, mpp);
    }
};
