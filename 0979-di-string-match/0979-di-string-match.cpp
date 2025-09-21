class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans;
        ans.reserve(n+1); // optimization

        int low = 0, high = n;
        for (char c : s) {
            if (c == 'I') {
                ans.push_back(low++);
            } else { // 'D'
                ans.push_back(high--);
            }
        }
        ans.push_back(low); // last one left (low == high)
        return ans;
    }
};
