class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    level.push_back(INT_MIN); // 🔥 FIX
                }
            }

            int st = 0, end = level.size() - 1;
            while(st < end){
                if(level[st] != level[end]) return false;
                st++;
                end--;
            }
        }

        return true;
    }
};