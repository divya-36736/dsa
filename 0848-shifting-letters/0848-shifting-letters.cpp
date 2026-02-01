class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        long long totalshifts = 0;
        for (int i = n - 1; i >= 0; i--) {
            totalshifts += shifts[i];
            s[i] = 'a' + (s[i] - 'a' + totalshifts) % 26;
        }
        return s;
    }
};