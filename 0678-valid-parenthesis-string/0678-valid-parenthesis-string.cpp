// class Solution {
// public:
//     bool ValidString(string& s, int idx, int cnt) {
//         int n = s.size();
//         if (cnt < 0) return false;
//         if (idx == n) return (cnt == 0); 
//         if(s[idx] == '('){
//             return ValidString(s, idx+1, cnt+1);
//         }
//         if(s[idx] == ')'){
//             return ValidString(s, idx+1, cnt-1);
//         }

//         return ValidString(s, idx+1, cnt+1) || ValidString(s, idx+1, cnt-1) || ValidString(s, idx+1, cnt);
//     }
    
//     bool checkValidString(string s) {
//         int idx = 0;
//         int cnt = 0;
//         return ValidString(s, idx, cnt);
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