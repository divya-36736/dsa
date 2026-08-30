class Solution {
public:
    int reverse(int x) {

        int sign = 1;
        sign = (x < 0)? -1 : 1;
        int rem;
        int ans = 0;
        while(x){
            rem = x % 10;
            if(ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
            ans = ans * 10 + rem;
            x /= 10;
        }
        return ans;
    }
};