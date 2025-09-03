class Solution {
public:
    int findMin(vector<int>& bloomDay) {
        int n = bloomDay.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, bloomDay[i]);
        }
        return ans;
    }
    int findMax(vector<int>& bloomDay) {
        int n = bloomDay.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, bloomDay[i]);
        }
        return ans;
    }

    bool isPossible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int noOfB = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        if (noOfB >= m)
            return true;
        else
            return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if (val > n) return -1;
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k) == true) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};