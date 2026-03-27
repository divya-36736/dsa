class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long ans = 0;
        vector<int>last(26, -1);
        for(int i = 0; i<n; i++){
            int ch = s[i] - 'a';
            ans += 1ll*(i-last[ch])*(n-i);
            last[ch] = i;
        }
        return ans;
    }
};