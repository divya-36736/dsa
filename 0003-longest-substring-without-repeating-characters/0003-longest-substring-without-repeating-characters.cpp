class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int>st;
        int maxlen = 0;
        int l = 0;
        int r = 0;
        while(r<n){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};