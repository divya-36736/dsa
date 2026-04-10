/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return s;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* currnode = q.front();
            q.pop();
            if(!currnode){
                s += "#,";
            }else{
                s += to_string(currnode->val)+",";
                q.push(currnode->left);
                q.push(currnode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*>q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* currnode = q.front();
            q.pop();
            getline(s, str, ',');
            if(str != "#"){
                TreeNode* nodeleft = new TreeNode(stoi(str));
                currnode->left = nodeleft;
                q.push(nodeleft);
            }
            getline(s, str, ',');
            if(str != "#"){
                TreeNode* noderight = new TreeNode(stoi(str));
                currnode->right = noderight;
                q.push(noderight);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));