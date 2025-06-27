// class Solution {
// public:
//     bool ValidString(string& s, int idx, int cnt, int n, vector<vector<int>>& memo) {
//         if (cnt < 0) return false; // More ) than (, invalid
//         if (idx == n) return (cnt == 0); // Valid if balanced at end
        
//         // Memoization: Use idx and cnt as state
//         if (memo[idx][cnt + n] != -1) return memo[idx][cnt + n];
        
//         if (s[idx] == '(') {
//             return memo[idx][cnt + n] = ValidString(s, idx + 1, cnt + 1, n, memo);
//         }
//         if (s[idx] == ')') {
//             return memo[idx][cnt + n] = ValidString(s, idx + 1, cnt - 1, n, memo);
//         }
//         // For *, try all three possibilities: (, ), or empty
//         return memo[idx][cnt + n] = (
//             ValidString(s, idx + 1, cnt + 1, n, memo) || // As (
//             ValidString(s, idx + 1, cnt - 1, n, memo) || // As )
//             ValidString(s, idx + 1, cnt, n, memo)       // As empty
//         );
//     }
    
//     bool checkValidString(string s) {
//         int n = s.size();
//         // Memo array: idx from 0 to n, cnt from -n to n (offset by n)
//         vector<vector<int>> memo(n + 1, vector<int>(2 * n + 1, -1));
//         return ValidString(s, 0, 0, n, memo);
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // Min possible open parentheses
        int maxOpen = 0; // Max possible open parentheses
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat * as )
                maxOpen++; // Treat * as (
            }
            if (maxOpen < 0) return false; // Too many ), even with * as (
            if (minOpen < 0) minOpen = 0; // * as empty to keep minOpen >= 0
        }
        return minOpen == 0; // Valid if minOpen can be 0
    }
};