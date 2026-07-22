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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int, int>>>q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int col = it.second.first;
            int row = it.second.second;
            TreeNode* node = it.first;
            nodes[col][row].insert(node->val);

            if(node->left){
                q.push({node->left, {col-1, row+1}});
            }
            if(node->right){
                q.push({node->right, {col+1, row+1}});
            }
        }

        vector<vector<int>>ans;
        for(auto &it1:nodes){
            vector<int>col;
            for(auto &it2:it1.second){
                for(auto &it3: it2.second){
                    col.push_back(it3);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};