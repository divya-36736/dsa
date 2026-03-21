class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        vector<int>hash(256, -1);
        while(l<=r && r<n){
            //character find
            if(hash[s[r]] != -1){
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxlen = max(maxlen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};