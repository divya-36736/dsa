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
        int maxlen = 0;

        while(!q.empty()){
            int size = q.size();
            int stidx = q.front().second;
            int endidx = q.back().second;

            maxlen = max(maxlen, endidx-stidx+1);
            for(int i = 0; i<size; i++){
                TreeNode* parent = q.front().first;
                int parentIdx = q.front().second;
                q.pop();

                if(parent->left){
                    q.push({parent->left, 2LL*parentIdx+1});
                }
                if(parent->right){
                    q.push({parent->right, 2LL*parentIdx+2});
                }
            }
        }
        return maxlen;
    }
};