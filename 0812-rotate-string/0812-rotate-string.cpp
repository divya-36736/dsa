class Solution {
public:
    bool rotateString(string s, string goal) {
        int s1 = s.size();
        if (s1 != goal.size()) return false;

        for (int shift = 0; shift < s1; shift++) {
            bool match = true;
            for (int j = 0; j < s1; j++) {
                int rot = (shift + j) % s1;
                if (s[rot] != goal[j]) {
                    match = false;
                    break; // stop checking this rotation
                }
            }
            if (match) return true; // found a matching rotation
        }
        return false; // no rotation matched
    }
};
