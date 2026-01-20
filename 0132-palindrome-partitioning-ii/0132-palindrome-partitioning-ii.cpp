class Solution {
public:
    bool isPalindrom(string &temp){
        int i = 0, j = temp.size() - 1;
        while(i < j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, string &s, vector<int> &dp){
        int n = s.size();
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        string temp = "";
        int minCost = INT_MAX;

        for(int j = i; j < n; j++){
            temp += s[j];
            if(isPalindrom(temp)){
                int cost = 1 + f(j + 1, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
    }
};
