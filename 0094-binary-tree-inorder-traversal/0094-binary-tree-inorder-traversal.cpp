/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    void inorder(TreeNode* node, vector<int>& result) {
        // if(node == nullptr) return;
        // inorder(node->left, result);
        // result.push_back(node->val);
        // inorder(node->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> result;
        // inorder(root, result);
        // return result;

        // // iterative method left root r
        // vector<int> inorder;   // Stores the result
        // stack<TreeNode*> st;   // Stack for simulation
        // TreeNode* curr = root; // Start from root

        // while (curr != NULL || !st.empty()) {
        //     // Step 1: Go to the leftmost node
        //     while (curr != NULL) {
        //         st.push(curr);
        //         curr = curr->left;
        //     }

        //     // Step 2: Process top of stack
        //     curr = st.top();
        //     st.pop();
        //     inorder.push_back(curr->val);

        //     // Step 3: Go to right subtree
        //     curr = curr->right;
        // }

        // return inorder;

        // morris inorder traversal

        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    // Make temporary thread
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    // Remove thread and visit node
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};