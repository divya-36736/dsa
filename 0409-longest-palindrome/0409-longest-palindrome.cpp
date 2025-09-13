class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        vector<int> lower(26, 0); // lowercase count
        vector<int> upper(26, 0); // uppercase count

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lower[s[i] - 'a']++;
            } else {
                upper[s[i] - 'A']++;
            }
        }

        int cnt = 0;
        bool odd = 0;

        for (int i = 0; i < 26; i++) {
            // lowercase
            if (lower[i] % 2 == 0) {
                cnt += lower[i];
            } else {
                cnt += lower[i] - 1;
                odd = 1;
            }
            // uppercase
            if (upper[i] % 2 == 0) {
                cnt += upper[i];
            } else {
                cnt += upper[i] - 1;
                odd = 1;
            }
        }

        return cnt + odd; // odd=1 means one center char allowed
    }
};
