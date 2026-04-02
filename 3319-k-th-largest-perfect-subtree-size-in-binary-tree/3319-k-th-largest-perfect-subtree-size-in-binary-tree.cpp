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
    vector<int>ans;
    pair<bool, int>make_tree(TreeNode* root){
        if(!root) return {true, 0};

        pair<bool, int>l = make_tree(root->left);
        pair<bool, int>r = make_tree(root->right);

        if(l.first && r.first && l.second == r.second){
            int s = l.second+r.second+1;
            ans.push_back(s);
            return {true, s};
        }
        return {false, 0};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(!root) return -1;
        ans.clear();
        make_tree(root);
        sort(ans.begin(), ans.end());
        int n = ans.size();

        if(ans.size() >= k){
            return ans[n-k];
        }
        return -1;
    }
};