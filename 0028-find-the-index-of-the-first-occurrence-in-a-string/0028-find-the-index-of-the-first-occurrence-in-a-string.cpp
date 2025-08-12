class Solution {
public:
    void lpsfind(vector<int>& lps, const string &s) {
        int n = s.size();
        if (n == 0) return;
        int pre = 0, suf = 1;
        while (suf < n) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int f = 0, sec = 0;
        while (f < haystack.size()) {
            if (haystack[f] == needle[sec]) {
                f++; sec++;
                if (sec == needle.size()) {
                    return f - sec; // found match
                }
            } else {
                if (sec == 0) {
                    f++;
                } else {
                    sec = lps[sec - 1];
                }
            }
        }
        return -1;
    }
};
