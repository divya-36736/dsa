class Solution {
public:
    bool ispalin(string &s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(ispalin(s, i, j)){
                    int len = j-i+1;
                    if(len>maxi){
                        maxi = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        return ans;
    }
};