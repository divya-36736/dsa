class Solution {
public:
    const long long MOD = 1e9+7;
    long long power(long long base, long long exp){
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        
        if(n == 0) return 1;
        //int 0-9 we have evevn number is 0, 2, 4, 6, 8 and prime number is 2, 3, 5, 7
        //then at evevn places have 5 choice and at odd places have 4 choices

        long long evencount = (n+1)/2;
        long long oddcount = n/2;

        
        long long even = power(5, evencount);//no of even indexeds
        long long odd = power(4, oddcount);//no of odd indexes

        return (even*odd)%MOD;
        
    }
};