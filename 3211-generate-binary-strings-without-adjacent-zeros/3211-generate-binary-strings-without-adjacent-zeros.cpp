class Solution {
public:
    void helper(int n, string &curr, vector<string>&ans){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back('1');
        helper(n, curr, ans);
        curr.pop_back();

        if(curr.empty() || curr.back() != '0'){
            curr.push_back('0');
            helper(n, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string curr = "";
        helper(n, curr, ans);
        return ans;
    }
};