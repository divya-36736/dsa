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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int maxwidth = 0;

        while(!q.empty()){
            int size = q.size();
            int stidx = q.front().second;
            int endidx = q.back().second;
            
            maxwidth = max(maxwidth, endidx - stidx +1);

            for(int i = 0; i<size; i++){
                auto p = q.front();
                q.pop();
                int parentidx = p.second;
                if(p.first->left){
                    q.push({p.first->left, 2LL*parentidx+1});
                }
                if(p.first->right){
                    q.push({p.first->right, 2LL*parentidx+2});
                }
            }
        }
        return maxwidth;
    }
};