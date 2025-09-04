class Solution {
public:
    bool backtrack(int i, string& s, unordered_set<string>& dict, vector<int>&dp) {
//Start from index 0 of string s. At each step,try every word in wordDict.
//If a word matches the substring starting at the current index :
//Recursively call backtrack with the new index =start + word.size().
//If you reach start ==s.size(), return true.

//base case
            if (i == s.size()) return true; // reached the end successfully
            if(dp[i] != -1) return dp[i];
        for (string word : dict) {
            int len = word.size();
            if (i + len <= s.size() && s.substr(i, len) == word) {
                if (backtrack(i + len, s, dict, dp))
                    return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(), -1);
        unordered_set<string> dict(wordDict.begin(),
                                   wordDict.end()); // remove repetation
        return backtrack(0, s, dict, dp);               // index , string s, set
    }
};
