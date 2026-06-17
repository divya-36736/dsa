class Solution {
public:
    int const mod = 1e9+7;
    long long power(long long base, long long exp){
        if(exp == 0 || base == 1) return 1;
        long long res = 1;
        while(exp){
            if(exp & 1){
                res = (res * base)%mod;
            }
            base = (base * base)%mod;
            exp >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        if(n == 0) return 1;

        long long evencount = (n+1)/2;
        long long oddcount = n/2;

        long long even = power(5, evencount);
        long long odd = power(4, oddcount);

        long long res = (even*odd)%mod;

        return (int)(res);
    }
};