class Solution {
public:
    string convertToTitle(int columnNumber) {
       string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
       string res = "";
       while(columnNumber>0){
        columnNumber--;
        int remainder = columnNumber%26;
        res += letters[remainder];
        columnNumber /= 26;
       }
       reverse(res.begin(), res.end());
       return res;
    }
};