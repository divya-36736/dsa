class Solution {
public:
    bool f(int i, string s, unordered_set<string>&Dict, vector<int>&dp){
        if(i == s.size()) return true;

        if(dp[i] != -1) return dp[i];

        for(auto &word:Dict){
            int len = word.size();
            if(i+len <= s.size() && s.substr(i, len) == word){
                if(f(i+len, s, Dict, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>word(wordDict.begin(), wordDict.end());
        vector<int>dp(n, -1);
        return f(0, s, word, dp);
    }
};