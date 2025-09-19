class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1, right = n, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long coins = mid * (mid + 1) / 2;

            if (coins <= n) {
                ans = mid;   // mid is possible, try bigger
                left = mid + 1;
            } else {
                right = mid - 1; // too many coins
            }
        }

        return (int)ans;
    }
};
