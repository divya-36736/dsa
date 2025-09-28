// class Solution {
// public:
//     string pushDominoes(string dominoes) {
//         int n = dominoes.size();
//         if (n <= 1) return dominoes;
//         string ans = "";

//         // handle 0th position safely
//         if (dominoes[0] == 'L' || dominoes[0] == 'R') ans += dominoes[0];
//         else if (n > 1 && dominoes[0] == '.' && dominoes[1] == 'L') ans += 'L';
//         else ans += '.';

//         for (int i = 1; i < n - 1; i++) {
//             if (dominoes[i] == 'L' || dominoes[i] == 'R') {
//                 ans += dominoes[i];
//             } else {
//                 if (dominoes[i - 1] == 'R' && dominoes[i + 1] != 'L') ans += 'R';
//                 else if (dominoes[i + 1] == 'L' && dominoes[i - 1] != 'R') ans += 'L';
//                 else ans += '.';
//             }
//         }

//         // handle last position safely
//         if (dominoes[n - 1] == 'L' || dominoes[n - 1] == 'R') ans += dominoes[n - 1];
//         else if (n > 1 && dominoes[n - 1] == '.' && dominoes[n - 2] == 'R') ans += 'R';
//         else ans += '.';

//         return ans;
//     }
// };


class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);

        // Left to Right pass → count 'R' force
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') force = n; 
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        // Right to Left pass → count 'L' force
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') force = n; 
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        // Build result
        string ans;
        for (int f : forces) {
            if (f > 0) ans += 'R';
            else if (f < 0) ans += 'L';
            else ans += '.';
        }
        return ans;
    }
};
