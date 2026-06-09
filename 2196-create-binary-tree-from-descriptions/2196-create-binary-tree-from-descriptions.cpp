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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>children;

        int n = descriptions.size();
        for(auto &e: descriptions){
            int p = e[0];
            int c = e[1];
            int isl = e[2];
            if(mp.find(p) == mp.end()){
                mp[p] = new TreeNode(p);
            }
            if(mp.find(c) == mp.end()){
                mp[c] = new TreeNode(c);
            }
            if(isl == 1){
                mp[p]->left = mp[c];
            }else{
                mp[p]->right = mp[c];
            }
            children.insert(c);
        }
        for(auto &it: mp){
            if(children.find(it.first) == children.end()){
                return it.second;
            }
        }
        return nullptr;
    }
};