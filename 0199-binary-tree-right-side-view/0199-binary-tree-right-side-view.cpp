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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>level;

            for(int i = 0; i<size; i++){
                TreeNode* top = q.front();
                level.push_back(top->val);
                q.pop();

                if(top->left != NULL) q.push(top->left);
                if (top->right != NULL)  q.push(top->right);
            } 
            ans.push_back(level);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        vector<vector<int>>levelTraversal = levelOrder(root);
        for(auto level: levelTraversal){
            res.push_back(level.back());
        }
        return res;
    }
};