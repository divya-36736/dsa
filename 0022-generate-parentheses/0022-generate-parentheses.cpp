class Solution {
public:
    void help(int n, int op, int cl, string curr, vector<string>&ans){
        if(op == n && cl == n){
            ans.push_back(curr);
            return;
        }

        if(op < n){
            help(n, op+1, cl, curr+"(", ans);
        }
        if(cl < op){
            help(n, op, cl+1, curr+")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr = "";
        help(n, 0, 0, curr, ans);
        return ans;
    }
};