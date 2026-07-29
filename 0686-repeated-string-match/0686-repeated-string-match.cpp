class Solution {
public:
    const long long MOD = 1000000007;
    const long long BASE = 31;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = (ans * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int repeatedStringMatch(string a, string b) {

        string text = a;
        int cnt = 1;

        while (text.size() < b.size()) {
            text += a;
            cnt++;
        }

        for (int t = 0; t < 2; t++) {

            int n = text.size();
            int m = b.size();

            vector<long long> p(n + 1);
            vector<long long> inv(n + 1);
            vector<long long> prefix(n + 1);

            p[0] = 1;

            for (int i = 1; i <= n; i++)
                p[i] = (p[i - 1] * BASE) % MOD;

            long long invBase = power(BASE, MOD - 2);

            inv[0] = 1;

            for (int i = 1; i <= n; i++)
                inv[i] = (inv[i - 1] * invBase) % MOD;

            // Prefix Hash
            for (int i = 0; i < n; i++) {

                long long val = text[i] - 'a' + 1;

                prefix[i + 1] = (prefix[i] + val * p[i]) % MOD;
            }

            // Pattern Hash
            long long patternHash = 0;

            for (int i = 0; i < m; i++) {

                patternHash = (patternHash +
                               (long long)(b[i] - 'a' + 1) * p[i]) % MOD;
            }

            // Sliding Window
            for (int i = 0; i + m <= n; i++) {

                long long cur =
                    (prefix[i + m] - prefix[i] + MOD) % MOD;

                cur = (cur * inv[i]) % MOD;

                if (cur == patternHash) {

                    bool ok = true;

                    for (int j = 0; j < m; j++) {

                        if (text[i + j] != b[j]) {

                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                        return cnt;
                }
            }

            text += a;
            cnt++;
        }

        return -1;
    }
};