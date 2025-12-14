class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        while (k-- > 0) {
            // sort every time to get current maximum
            sort(gifts.begin(), gifts.end());

            // pick the largest gift
            gifts[n - 1] = sqrt(gifts[n - 1]);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += gifts[i];
        }

        return sum;
    }
};
