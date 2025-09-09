class Solution {
public:
    const int mod = 1e9+7;
    int f(int i, int n, int delay, int forget, vector<int>&dp){
        if(i<0)return 0; // No negative days
        if(i==0) return 1;// On day 0, exactly 
        //1 person learns the secret
        if(i<delay) return 0; // Before delay, no new people can learn
        if(dp[i]!=-1)return dp[i];

        long long ans  =0;
        for(int j = max(0, i-forget+1); j<=(i-delay); j++){
            ans += f(j, n, delay, forget, dp);
            ans %= mod;
        }
        return dp[i] = ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n, -1);
        long long ans  = 0;
        //At the end of day n, count all people who still remember
        for(int i = n-forget; i<n; i++){
            ans += f(i, n, delay, forget, dp);
            ans %= mod;
        }
        return (int)ans;
    }
};