class Solution {
public:
    const int mod = 1e9+7;

    int countHousePlacements(int n) {
        vector<long long> dp(n+1, 0);
        long long prev2 = 1;
        long long prev1 = 2;
        long long curr;

        for(int i = 2; i<=n; i++){
            curr = (prev1+prev2)%mod;
            prev2 = prev1;
            prev1 = curr;
        }

        return (prev1*prev1) % mod;   
    }
};