class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int h = happiness.size();
        sort(happiness.begin(), happiness.end());  // keep your sort

        long long sum = 0;
        int i = h - 1;
        int taken = 0;

        while (k > 0 && i >= 0) {
            long long curr = happiness[i] - taken;
            if (curr <= 0) break;

            sum += curr;
            taken++;   // instead of decreasing all others
            k--;
            i--;
        }

        return sum;
    }
};
