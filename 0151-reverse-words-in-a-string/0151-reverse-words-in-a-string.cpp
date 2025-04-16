class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        string ans = "";
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (!word.empty()) {
                if (!ans.empty())
                    ans += " ";
                ans += word;
            }
        }
        return ans;
    }
};
