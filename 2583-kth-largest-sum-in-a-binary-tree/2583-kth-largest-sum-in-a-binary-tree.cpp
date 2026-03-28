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
    vector<long long> level(TreeNode* root){
        vector<long long>res;
        if(root == NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            long long sum = 0;
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            res.push_back(sum);
        }
        return res;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>res = level(root);
        int n = res.size();
        if(k > n) return -1;
        sort(res.begin(), res.end());
        return res[n-k];
    }
};