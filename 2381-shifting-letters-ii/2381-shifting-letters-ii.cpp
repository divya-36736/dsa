class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        // difference array
        for (auto &sh : shifts) {
            int start = sh[0];
            int end = sh[1];
            int dir = sh[2];

            int val = (dir == 1) ? 1 : -1;
            diff[start] += val;
            diff[end + 1] -= val;
        }

        //Prefix sum  apply shifts
        int currShift = 0;
        for (int i = 0; i < n; i++) {
            currShift += diff[i];

            // handle negative shifts safely
            int shift = (currShift % 26 + 26) % 26;

            s[i] = 'a' + ( (s[i] - 'a' + shift) % 26 );
        }

        return s;
    }
};
