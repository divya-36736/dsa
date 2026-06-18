class Solution {
public:
    void helper(int n, string curr, char prev, vector<string>& ans) {
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        helper(n, curr + '1', '1', ans);

        if(prev != '0'){
            helper(n, curr + '0', '0', ans);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n, "", '1', ans);
        return ans;
    }
};