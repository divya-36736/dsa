class Solution {
public:
    string reversePrefix(string s, int k) {
        string prefix = s.substr(0, k);
        reverse(prefix.begin(), prefix.end());
        prefix += s.substr(k);

        return prefix;
    }
};
