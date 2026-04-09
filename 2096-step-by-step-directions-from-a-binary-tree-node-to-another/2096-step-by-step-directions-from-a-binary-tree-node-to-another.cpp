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
        string pathStart ="";
        string pathDesti ="";

        getPath(root, startValue, pathStart);
        getPath(root, destValue, pathDesti);

        int i = 0;
        while(i<pathStart.size() && i<pathDesti.size() && pathStart[i] == pathDesti[i]){
            i++;
        }

        string res = "";
        for(int k = i; k<pathStart.size(); k++){
            res += 'U';
        }

        res += pathDesti.substr(i);

        return res;
    }
};