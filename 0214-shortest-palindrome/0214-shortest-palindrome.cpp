class Solution {
public:
    string shortestPalindrome(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        int n = temp.size();
        vector<int> lps(n, 0);

        int len = 0;

        for (int i = 1; i < n;) {

            if (temp[i] == temp[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longest = lps[n - 1];

        string rem = s.substr(longest);

        reverse(rem.begin(), rem.end());

        return rem + s;
    }
};