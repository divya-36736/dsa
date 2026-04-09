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
    TreeNode* LCA(TreeNode* root, int p, int q){
        if(!root || root->val == p || root->val == q){
            return root;
        }

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if(!left){
            return right;
        }
        else if(!right) return left;

        else return root;
    }
    bool getPath(TreeNode* root, int target, string &path){
        if(!root) return false;

        if(root->val == target) return true;

        path.push_back('L');
        if(getPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(getPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }


    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);
        string pathStart ="";
        string pathDesti ="";

        getPath(lca, startValue, pathStart);
        getPath(lca, destValue, pathDesti);

        string res = "";
        for(int i = 0; i<pathStart.size(); i++){
            res += 'U';
        }

        res = res+pathDesti;
        return res;
    }
};