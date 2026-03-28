/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int level(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        long long maxi = INT_MIN;
        int cnt = 0;
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += (long long)node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(sum > maxi){
                maxi = sum;
                cnt = level;
            }
            level++;
        }
        return cnt;
    }
    int maxLevelSum(TreeNode* root) {
        return level(root);
    }
};