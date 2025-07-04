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
private: 
    int check(TreeNode* node){
        if(node == NULL) return 0;
        int lh =  check(node->left);
        if(lh == -1) return -1;
        int rh = check(node->right);
        if(rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh, rh) + 1;
    }

// private:
//     bool check(TreeNode* node){
//         if(node == NULL) return true;
//         int lh = findHleft(node->left);
//         int rh = findHright(node->right);
//         if(abs())
//     }

public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;

        
    }
};