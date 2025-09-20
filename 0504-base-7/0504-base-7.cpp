class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ans = "";
        int negative = false;
        int temp = num;
        if(num<0){
            negative = true;
            temp = -temp;
        }
        while(temp>0){
            ans = (char)(temp % 7 + '0') + ans;
            temp /= 7;
        }
        if (negative) ans = '-' + ans;
        return ans;
    }
};