class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        // Count letters in magazine
        for (char c : magazine) {
            freq[c - 'a']++;
        }

        // Check ransomNote letters
        for (char c : ransomNote) {
            if (freq[c - 'a'] == 0) {
                return false; // letter not available
            }
            freq[c - 'a']--; // use one occurrence
        }
        return true;
    }
};
