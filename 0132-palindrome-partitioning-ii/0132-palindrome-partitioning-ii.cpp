class Solution {
public:
    bool isPalindrom(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = -1; 

        for(int i = n - 1; i >= 0; i--){
            int minCuts = INT_MAX;
            for(int j = i; j < n; j++){
                if(isPalindrom(i, j, s)){
                    int cost = 1 + dp[j + 1];
                    minCuts = min(minCuts, cost);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0];
    }
};
