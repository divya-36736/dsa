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
    unordered_map<int, vector<int>>graph;
    void constructGraph(TreeNode* root){
        if(!root) return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        constructGraph(root->left);
        constructGraph(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        constructGraph(root);
        queue<int>q;
        q.push(target->val);
        unordered_set<int>visited;
        vector<int>ans;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                return ans;
            }
            for(int i = size; i>0; i--){
                int node = q.front();
                q.pop();
                visited.insert(node);
                for(int adjnode : graph[node]){
                    if(!visited.count(adjnode)){
                        visited.insert(adjnode);
                        q.push(adjnode);
                    }
                }
            }
            dist++;
        }
        return {};
    }
};