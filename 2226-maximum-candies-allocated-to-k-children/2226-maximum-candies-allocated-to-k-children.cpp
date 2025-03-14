class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        int maxCandy = 0;

        for(int i = 0; i < n; i++){
            sum += candies[i];
            maxCandy = max(maxCandy, candies[i]);
        }

        if(sum < k){
            return 0;
        }

        int left = 1, right = maxCandy, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long count = 0;

            for (int c : candies) {
                count += c / mid;  // Count how many children can get 'mid' candies
            }

            if (count >= k) {  
                result = mid;  
                left = mid + 1;  // Try to maximize the answer
            } else {
                right = mid - 1;  // Reduce mid
            }
        }

        return result;
    }
};
