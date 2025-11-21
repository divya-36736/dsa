class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int count = 0;
        bool seen[26][26] = {false}; // seen[first_char][middle_char]
        int first[26], last[26];

        // Initialize first and last occurrence arrays
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
            last[idx] = i;
        }

        // Check for each character as first/last of palindrome
        for (int c1 = 0; c1 < 26; c1++) {
            if (first[c1] != -1 && first[c1] < last[c1]) {
                // Track unique middle characters between first and last
                for (int i = first[c1] + 1; i < last[c1]; i++) {
                    int c2 = s[i] - 'a';
                    if (!seen[c1][c2]) {
                        seen[c1][c2] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
