class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int ans  = 1;
        for(int i = 1; i<=x/2; i++){
            long long sq = 1LL*i*i;
            if(sq == x) return i;
            if(sq > x) return i-1;
            ans = i;
        } 
        return ans;
    }
};