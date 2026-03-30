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
    vector<int> postorderTraversal(TreeNode* root) {
        //using one stack
        vector<int>post;
        stack<TreeNode*>st;
        TreeNode*lastvisit = NULL;
        while(root != NULL || !st.empty()){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* peekNode = st.top();
                if(peekNode->right != NULL && lastvisit != peekNode->right){
                    root = peekNode->right;
                }else{
                    post.push_back(peekNode->val);
                    lastvisit = peekNode;
                    st.pop();
                }
            }
        }
        return post;
    }
};