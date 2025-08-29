class Solution {
public:
    bool isPallindrom(string &s, int l, int r){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;  
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxi = 0; 
        string ans = "";
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isPallindrom(s, i, j)){
                    int len = (j-i+1);
                    if(len > maxi){
                        maxi = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }    
        return ans;
    }
};