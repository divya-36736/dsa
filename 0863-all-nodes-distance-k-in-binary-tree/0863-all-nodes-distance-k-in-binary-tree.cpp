/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left) {
                    parent[top->left->val] = top;
                    q.push(top->left);
                }
                if (top->right) {
                    parent[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }
        unordered_map<int, int>visited;
        q.push(target);
        while (k > 0 && !q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                visited[node->val] = 1;
                if(node->left && !visited[node->left->val]){
                    q.push(node->left);
                }
                if(node->right && !visited[node->right->val]){
                    q.push(node->right);
                }
                if(parent[node->val] && !visited[parent[node->val]->val]){
                    q.push(parent[node->val]);
                }
            }
            k--;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};