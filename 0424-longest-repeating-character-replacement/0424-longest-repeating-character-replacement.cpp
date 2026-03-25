class Solution {
public:
    int changes(string s, int k, char target) {
        int n = s.size();
        int left = 0;
        int cnt = 0; // number of changes used
        int maxlen = 0;

        for (int right = 0; right < n; right++) {
            if (s[right] != target) {
                cnt++; // need to change this
            }

            while (cnt > k) {
                if (s[left] != target) {
                    cnt--;
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }

    int characterReplacement(string s, int k) {
        int ans = 0;

        // try making all characters equal to each letter
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            ans = max(ans, changes(s, k, ch));
        }

        return ans;
    }
};