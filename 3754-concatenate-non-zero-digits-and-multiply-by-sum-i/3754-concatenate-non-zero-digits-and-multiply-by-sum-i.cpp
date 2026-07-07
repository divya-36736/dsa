class Solution {
    public:
        long long sumAndMultiply(int n) {
            long long x = 0;
            int r = 1;
            int sum_digits = 0;
            while (n > 0) {
                int d = n % 10;
                n /= 10;
                if (d == 0) continue;
                x = d * r + x;
                sum_digits += d;
                r *= 10;
            }
            return x * sum_digits;
        }
};