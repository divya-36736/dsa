class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int result = 0;

        // first[i] = first location of character 'a'+i
        // last[i]  = last  location of character 'a'+i
        vector<int> first(26, -1), last(26, -1);

        // Fill first & last index of each character
        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }

        // For every character, count how many different characters
        // exist between its first and last appearance.
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && first[c] < last[c]) {
                // Use a small array to mark which middle characters we saw
                vector<bool> present(26, false);

                // Check characters in between
                for (int i = first[c] + 1; i < last[c]; i++) {
                    present[s[i] - 'a'] = true;
                }

                // Count how many different middle characters exist
                for (int m = 0; m < 26; m++) {
                    if (present[m]) result++;
                }
            }
        }

        return result;
    }
};
