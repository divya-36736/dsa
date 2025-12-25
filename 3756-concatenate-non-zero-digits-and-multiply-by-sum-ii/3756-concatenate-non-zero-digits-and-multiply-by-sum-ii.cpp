class Solution {
public:
    static const long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        
        vector<long long> cnt(n + 1, 0);       
        vector<long long> sumDigit(n + 1, 0);  
        vector<long long> val(n + 1, 0);       
        vector<long long> pow10(n + 1, 1);    

        
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            sumDigit[i + 1] = sumDigit[i];
            val[i + 1] = val[i];

            if (s[i] != '0') {
                int d = s[i] - '0';
                cnt[i + 1]++;
                sumDigit[i + 1] += d;
                val[i + 1] = (val[i] * 10 + d) % MOD;
            }
        }

        vector<int> answer;

        // Process queries
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long k = cnt[r + 1] - cnt[l];   
            if (k == 0) {
                answer.push_back(0);
                continue;
            }

            long long sum = sumDigit[r + 1] - sumDigit[l];

            long long x = (val[r + 1] -
                           (val[l] * pow10[k]) % MOD + MOD) % MOD;

            long long res = (x * sum) % MOD;
            answer.push_back((int)res);
        }

        return answer;
    }
};