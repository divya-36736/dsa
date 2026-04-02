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
    vector<vector<int>>solve(TreeNode* root){
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }

    int minOp(vector<int>&v){
        int n = v.size();
        vector<int>sorted = v;

        sort(sorted.begin(), sorted.end());
        unordered_map<int, int>pos;
        for(int i = 0; i<n; i++){
            pos[v[i]] = i;
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(v[i] != sorted[i]){
                cnt++;
                int correct = sorted[i];
                //here index swaping
                int idx = pos[correct];
                pos[v[i]] = idx;
                pos[correct] = i;
                swap(v[i], v[idx]);
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>v = solve(root);
        int op = 0;
        for(auto x:v){
            op += minOp(x);
        }
        return op;
    }
};