class Solution {
public:
    string decimalToHexa(unsigned int num){
        if(num == 0) return "0";

        string hexChars = "0123456789abcdef";
       string ans = "";

       while(num>0){
        int rem = num%16;
        ans += hexChars[rem];
        num /= 16;
       }
       reverse(ans.begin(), ans.end());
       return ans;
    }
    string toHex(int num) {
        if(num<0){
            unsigned int nums = (unsigned int)num; //convet to 2's complement
            return decimalToHexa(nums);
        }
        return decimalToHexa(num);
    }
};