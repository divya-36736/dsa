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
        //1st we search the target
        vector<int>ans;
        unordered_map<int, TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size; i++){
                auto top = q.front();
                q.pop();

                if(top->left){
                    parent[top->left->val] = top;
                    q.push(top->left);
                }
                if(top->right){
                    parent[top->right->val]=top;
                    q.push(top->right);
                }
            }
        }
        unordered_map<int,int>vis;
        q.push(target);
        while(k-- && !q.empty()){
            int size = q.size();

            for(int i = 0;i<size; i++){
                auto top = q.front();
                q.pop();

                vis[top->val] = 1;

                if(top->left && !vis[top->left->val]){
                    q.push(top->left);
                }
                if(top->right && !vis[top->right->val]){
                    q.push(top->right);
                }
                if(parent[top->val] && !vis[parent[top->val]->val]){
                    q.push(parent[top->val]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};