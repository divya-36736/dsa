class Solution {
public:
    const int mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1, 0);
        //return memo(0, low, high, zero, one, dp);
        dp[0] = 1;
        int ways =0 ;
        for(int len = 0; len<=high; len++){
            if(len + zero <= high){
                dp[len+zero] = (dp[len+zero] + dp[len])%mod;
            }
            if(len + one <= high){
                dp[len+one] = (dp[len+one] + dp[len])%mod;
            }
        }

        for(int i = low; i<=high; i++){
            ways = (ways+dp[i])%mod;
        }
        return ways;
    }
};