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
    
    TreeNode* replaceValueInTree(TreeNode* root) {

        //level order avrsa nd sum of the level and updae the childnod with levelnod - childnode
        queue<TreeNode*>q;
        q.push(root);
        root->val = 0;
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*>nodes;
            int levelsum = 0;
            for(int i = 0; i<size; i++){
                TreeNode* top = q.front();
                q.pop();
                nodes.push_back(top);
                if(top->left){
                    levelsum += top->left->val;
                    q.push(top->left);
                }
                if(top->right){
                    levelsum += top->right->val;
                    q.push(top->right);
                }
            }
            //update child node
            for(auto &node:nodes){
                int childsum = 0;
                if(node->left) childsum += node->left->val;
                if(node->right) childsum += node->right->val;

                if(node->left){
                    node->left->val = levelsum - childsum;
                }
                if(node->right){
                    node->right->val = levelsum - childsum;
                }
            }
        }
        return root;
    }
};