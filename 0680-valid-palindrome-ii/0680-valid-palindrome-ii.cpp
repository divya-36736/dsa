class Solution {
public:
    bool palin(int l, int r, string &s){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            if(s[l] != s[r]){
                return palin(l+1, r, s) || palin(l, r-1, s);
            }
            l++;
            r--;
        }
        return true;
    }
};