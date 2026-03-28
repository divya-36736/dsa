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
    void inorder(TreeNode* root, unordered_map<int, int>&m, vector<int>&modes, int &maxcnt){
        if(root == NULL) return;
        inorder(root->left, m, modes, maxcnt);
        //push
        int cnt = m[root->val]++;
        if(cnt > maxcnt){
            maxcnt = cnt;
            modes.clear();
            modes.push_back(root->val);
        }else if(cnt == maxcnt){
            modes.push_back(root->val);
        }
        inorder(root->right, m, modes, maxcnt);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int ,int>m;
        vector<int>modes;
        int maxcnt = 0;
        inorder(root, m, modes, maxcnt);
        return modes;
    }
};