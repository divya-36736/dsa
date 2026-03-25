class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int maxfreq = 0;
        unordered_map<int, int>m;
        while(r<n){
            m[s[r]]++;
            maxfreq = max(maxfreq, m[s[r]]);
            
            if(r-l+1 - maxfreq > k){
                m[s[l]]--;
                if(m[s[l]] == 0){
                    m.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};