class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int len = j-i+1;
                string sub = s.substr(i,len);
                if(isPalindrome(sub, 0, sub.size()-1)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};