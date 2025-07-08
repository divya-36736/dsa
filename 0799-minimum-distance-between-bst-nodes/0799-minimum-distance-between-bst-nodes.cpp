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

    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return INT_MAX;
        int ans = INT_MAX;
        if(root->left != NULL){
            int leftMin = minDiffInBST(root->left);
            ans = min(ans, leftMin);
        }
        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;
        
        if(root->right){
            int rightMin = minDiffInBST(root->right);
            ans = min(ans, rightMin);
        }
        return ans;
        // vector<int>ans;
        // vector<int> ans1;
        // int min = 0;

        // inorder(root, ans);
        // for(int i =1; i<ans.size(); i++){
        //     ans1.push_back(ans[i] - ans[i-1]);
        // }

        // sort(ans1.begin(), ans1.end());
        // return ans1[0];

    }
};