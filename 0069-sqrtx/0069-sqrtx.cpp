class Solution {
public:
    int mySqrt(int x) {
        // if(x == 0 || x == 1) return x;
        // int ans  = 1;
        // for(int i = 1; i<=x/2; i++){
        //     long long sq = 1LL*i*i;
        //     if(sq == x) return i;
        //     if(sq > x) return i-1;
        //     ans = i;
        // }
        // return ans;

        // optimal
        if (x == 0 || x == 1)
            return x;

        int left = 1, right = x, ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2; // avoid overflow
            long long sq = mid * mid;

            if (sq == x)
                return mid;
            else if (sq < x) {
                ans = mid; // mid is a candidate
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};