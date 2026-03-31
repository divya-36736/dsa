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

    int amountOfTime(TreeNode* root, int start) {
        //convert to this in undirected graph using adjlist
        constructGraph(root);
        //BFS traversal

        queue<int>q;
        q.push(start);
        int minutes = 0;
        unordered_set<int>visited;
        while(!q.empty()){
            minutes++;
            int size = q.size();
            for(int i = size; i>0 ; i--){
                int node = q.front();
                q.pop();
                visited.insert(node);
                for(int adjnode: graph[node]){
                    if(!visited.count(adjnode)){
                        q.push(adjnode);
                    }
                }
            }
        }
        return minutes-1;
    }
};