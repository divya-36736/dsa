class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = INT_MIN;
        if(n == 0) return 0;
        for(int i = 0; i<n; i++){
            unordered_set<int>set;
            for(int j = i; j<n; j++){
                if (set.find(s[j]) != set.end())
                {
                    maxi = max(maxi, j - i);
                    break;
                }
            set.insert(s[j]);
            maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};