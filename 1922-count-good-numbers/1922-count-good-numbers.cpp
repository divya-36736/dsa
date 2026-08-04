class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);
        half = (half * half) % mod;

        if (n % 2 == 0)
            return half;

        return (half * x) % mod;
    }

    int countGoodNumbers(long long n) {

        long long evenPlaces = (n + 1) / 2;
        long long oddPlaces = n / 2;

        long long evenCnt = power(5, evenPlaces);
        long long oddCnt = power(4, oddPlaces);

        return (evenCnt * oddCnt) % mod;
    }
};