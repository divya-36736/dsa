class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, delay, forget;
    vector<long long> memo;

    long long solve(int day) {
        if (day == 1) return 1;      // Base case: day 1 person
        if (day > n) return 0;
        if (memo[day] != -1) return memo[day];

        long long sum = 0;
        int lb = max(1, day - forget + 1);
        int ub = day - delay;
        if (ub >= lb) {
            for (int j = lb; j <= ub; ++j) {
                sum = (sum + solve(j)) % MOD;
            }
        }
        return memo[day] = sum;
    }

    int peopleAwareOfSecret(int N, int Delay, int Forget) {
        n = N; delay = Delay; forget = Forget;
        memo.assign(n + 1, -1);

        long long ans = 0;
        for (int i = max(1, n - forget + 1); i <= n; ++i) {
            ans = (ans + solve(i)) % MOD;
        }
        return (int)ans;
    }
};
