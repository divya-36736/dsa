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
    void help(TreeNode* root, string ans, int &sum){
    if(!root) return;

    ans += to_string(root->val);

    if(!root->left && !root->right){
        int val = 0;
        int base = 1;
        for(int i = ans.size()-1; i>=0; i--){
            if(ans[i] == '1'){
                val += base;
            }
            base *= 2;
        }
        sum += val;
        return;
    }

    help(root->left, ans, sum);
    help(root->right, ans, sum);
}
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        string ans = "";
        int sum = 0;
        help(root, ans, sum);
        return sum;
    }
};