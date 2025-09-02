class Solution {
public:
    void backTrack(int n, int open, int close, string curr, vector<string>&ans){
        //base case
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }
        //1st add ( 
        if(open<n){
            backTrack(n, open+1, close, curr+"(", ans);
        }
        //after ( now we add )
        if(close < open){
            backTrack(n, open, close+1, curr+")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        backTrack(n, 0, 0, "", ans);
        return ans;
    }
};