class Solution {
public:
    const int mod = 1e9+7;

    long long ways(int n, vector<long long>& dp){
        if(n == 0) return 1;
        if(n == 1) return 2;

        if(dp[n] != -1) return dp[n];

        return dp[n] = (ways(n-1, dp) + ways(n-2, dp)) % mod; 
    }

    int countHousePlacements(int n) {
        vector<long long> dp(n+1, -1);

        long long way = ways(n, dp); 

        return (way * way) % mod;   
    }
};