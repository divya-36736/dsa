class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, long long hourly) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (pile + hourly - 1) / hourly; // ceil
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPiles = *max_element(piles.begin(), piles.end());

        int st = 1;              
        int end = maxPiles;
        long long ans = maxPiles;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            long long hours = calculateTotalHours(piles, mid);

            if (hours <= h) {       
                //ans = mid;
                end = mid - 1;      
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};
