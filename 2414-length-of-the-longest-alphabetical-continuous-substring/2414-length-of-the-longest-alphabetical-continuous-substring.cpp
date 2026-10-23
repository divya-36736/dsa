class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 1;
        int maxi = 1;
        while(r<n){
            if(s[r] == s[r-1]+1){
                r++;
            }else{
                l = r;
                r++;
            }
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
};