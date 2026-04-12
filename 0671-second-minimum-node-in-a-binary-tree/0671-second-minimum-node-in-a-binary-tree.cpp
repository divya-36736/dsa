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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        set<int>st;
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            st.insert(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        if(st.size()>=2){
            auto it = next(st.begin(), 1);
            return *it;
        }
        return -1;
    }
};