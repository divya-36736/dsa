class Solution {
public:
    // Function to check if we can repair 'cars' in 'mid' time
    bool isPossible(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;
        for (int r : ranks) {
            totalCars += (long long)sqrt(mid / r); // Max cars this mechanic can repair in 'mid' time
            if (totalCars >= cars) return true; // If we can repair enough cars, return true
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = (long long) *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        long long answer = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isPossible(ranks, cars, mid)) {
                answer = mid;
                right = mid - 1; // Try for a smaller time
            } else {
                left = mid + 1; // Increase time if it's insufficient
            }
        }
        return answer;
    }
};