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

    
    // void inorder(TreeNode* root, vector<int>&ans){
    //     if(root == NULL) return;
    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }

    void inorder(TreeNode* root, int &count, int k, int &smallest){
        if(root == NULL) return;
        inorder(root->left, count, k, smallest);
        count++;
        if(count == k){
            smallest = root->val;
            return;
        }
        inorder(root->right, count, k, smallest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int smallest = INT_MAX;
        inorder(root, count, k, smallest);
        return smallest;
        // vector<int>ans;
        // inorder(root, ans);
        // return ans[k-1];
    }
};