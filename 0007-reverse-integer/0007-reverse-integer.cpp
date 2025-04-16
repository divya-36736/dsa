class Solution {
public:
    int reverse(int x) {

        int r = 0;
        while(x != 0){
            int ans = x % 10;
            if((r > INT_MAX / 10) || (r < INT_MIN / 10)){
                return 0;
            }
            r = ans + r*10;
            x = x/10;
        }
        return r;
    }
};