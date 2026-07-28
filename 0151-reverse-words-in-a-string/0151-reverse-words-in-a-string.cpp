class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        string word = "";
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ' ') {
                if (!word.empty()) {
                    reverse(word.begin(), word.end());

                    if (!ans.empty())
                        ans += " ";

                    ans += word;
                    word.clear();
                }
            }
            else {
                word += s[i];
            }
        }

        if (!word.empty()) {
            reverse(word.begin(), word.end());

            if (!ans.empty())
                ans += " ";

            ans += word;
        }

        return ans;
    }
};