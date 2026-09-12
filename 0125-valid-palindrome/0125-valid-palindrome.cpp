class Solution {
public:
    bool check(int i, string &str){
        int n = str.size();
        if(i>=n/2) return true;

        if(tolower(str[i]) != tolower(str[n-i-1])) return false;
        return check(i+1, str);
    }
    bool isPalindrome(string s) {
        string str = "";
        for(char c: s){
            if(isalnum(c)){
                str += c;
            }
        }
        return check(0, str);
    }
};