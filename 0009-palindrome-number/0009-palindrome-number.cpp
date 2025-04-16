class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int original = x;
        int r = 0;
        while(x != 0){
            int ans = x%10;
            if((r>INT_MAX / 10) || (r<INT_MIN / 10)){
                return false;
            }
            r = ans + r * 10;
            x = x/10;
        }
       
        if(r == original){
            return true;
        }
        return false;
    }
};