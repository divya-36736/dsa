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
    void inorder(TreeNode* root, vector<int>&in){
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>in;
        inorder(root, in);
        vector<vector<int>>ans;
        int n = in.size();
        int q = queries.size();
        for(auto it:queries){
            int i = lower_bound(in.begin(), in.end(), it)-in.begin();
            if(i<n && in[i] ==it){
                ans.push_back({it, it});
            }
            else if(i == 0){
                ans.push_back({-1, in[i]});
            }
            else if(i == n){
                ans.push_back({in[i-1], -1});
            }else{
                ans.push_back({in[i-1], in[i]});
            }
        }
        return ans;
    }
};