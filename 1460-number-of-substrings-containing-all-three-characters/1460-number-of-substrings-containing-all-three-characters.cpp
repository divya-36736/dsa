class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0, 0, 0}; // Stores the count of 'a', 'b', and 'c'
        int left = 0, total = 0, n = s.size();

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++; // Update count for the current character

            // Check if we have at least one of each character in the window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                total += n - right; // Count substrings from left to the end
                count[s[left] - 'a']--; // Shrink the window
                left++;  
            }
        }
        
        return total;
    }
};