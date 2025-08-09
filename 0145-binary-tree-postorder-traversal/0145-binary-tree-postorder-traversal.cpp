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

private:
    // void postorder(TreeNode* node, vector<int>&result){
    //     if(node == nullptr) return;
    //     postorder(node->left, result);
    //     postorder(node->right, result);
    //     result.push_back(node->val);
    // }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> res;
        // postorder(root, res);
        // return res;
        vector<int>postorder;
        stack<TreeNode*>st1, st2;
        if(root == NULL) return postorder;
        //1st push root
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            //left child
            if(root->left != NULL) st1.push(root->left);
            //right childe
            if(root->right != NULL) st1.push(root->right);
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};