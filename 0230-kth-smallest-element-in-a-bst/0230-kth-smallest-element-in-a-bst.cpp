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
    int inorder(TreeNode* root, int k){
        stack<TreeNode*>st;
        TreeNode* curr = root;
        int ans = 0;
        int cnt = 0;
        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            cnt++;
            if(cnt == k){
                ans = curr->val;
            }
            curr = curr->right;
        }
        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};