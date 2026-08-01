class Solution {
public:
    long long mod = 1e9 + 7;

    long long hashValue(string s, long long base, int m) {
        long long factor = 1;
        long long ans = 0;

        for (int i = m - 1; i >= 0; i--) {
            ans = (ans + ((s[i] - 'a' + 1) * factor) % mod) % mod;
            factor = (factor * base) % mod;
        }

        return ans;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (n < m)
            return -1;

        long long base = 26;
        long long max_wt = 1;

        // base^(m-1)
        for (int i = 1; i < m; i++)
            max_wt = (max_wt * base) % mod;

        long long hashneedle = hashValue(needle, base, m);
        long long hashhay = 0;

        for (int i = 0; i <= n - m; i++) {

            if (i == 0) {
                hashhay = hashValue(haystack, base, m);
            } else {

                hashhay =
                    (((hashhay -
                       ((haystack[i - 1] - 'a' + 1) * max_wt) % mod +
                       mod) %
                          mod) *
                         base +
                     (haystack[i + m - 1] - 'a' + 1)) %
                    mod;
            }

            if (hashneedle == hashhay) {

                bool match = true;

                for (int j = 0; j < m; j++) {

                    if (needle[j] != haystack[i + j]) {
                        match = false;
                        break;
                    }
                }

                if (match)
                    return i;
            }
        }

        return -1;
    }
};