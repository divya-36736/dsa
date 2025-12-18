class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt = 1;   // at least 1 for first element
        long long len = 1;   // length of current descent

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                len++;       // extend descent
            } else {
                len = 1;     // reset
            }
            cnt += len;
        }
        return cnt;
    }
};
