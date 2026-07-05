class Solution {
public:
    bool ispalindrom(string &s, int i, int j){
        while(i<=j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    int f(int i, string s, vector<int>&dp){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int j = i; j<s.size(); j++){
            if(ispalindrom(s, i, j)){
                int cost = 1+f(j+1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        //return f(0, s, dp)-1;
        dp[n] = -1;
        for(int i = n-1; i>=0; i--){
            int mini = INT_MAX;
            for(int j = i; j<n; j++){
                if(ispalindrom(s, i, j)){
                    int cost = 1+dp[j+1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }
};