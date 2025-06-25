class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        int count = 0; // Track satisfied children
        int i = 0; // Pointer for children
        int j = 0; // Pointer for cookies
        
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) { // If current cookie satisfies current child
                count++; // Satisfy child
                i++; // Move to next child
                j++; // Move to next cookie
            } else {
                j++; // Try next cookie for same child
            }
        }
        
        return count;
    }
};