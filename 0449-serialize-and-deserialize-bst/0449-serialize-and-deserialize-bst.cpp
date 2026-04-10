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
            if(currnode == NULL){
                s += "#,";
            }else{
                s += to_string(currnode->val) + ",";
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
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str != "#"){
                TreeNode* nodeleft = new TreeNode(stoi(str));
                node->left = nodeleft;
                q.push(nodeleft);
            }
            getline(s, str, ',');
            if(str != "#"){
                TreeNode* noderight = new TreeNode(stoi(str));
                node->right = noderight;
                q.push(noderight);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;