class Solution {
public:
    long long countChild(vector<int>& candies, long long mid){
        long long totalChild = 0;
        for(int c : candies){
            totalChild += c/mid;
        }
        return totalChild;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        //int maxval = *max_element(candies.begin(), candies.end());
        int maxval = 0;
        long long sum = 0;
        for(int c : candies){
            sum += c;
            maxval = max(maxval, c);
        }
        if(sum < k) return 0;

        int st = 1;
        int end = maxval;

        int res = 0;
        while(st<=end){
            long long mid = st+(end-st)/2;
            long long children = countChild(candies, mid);
            if(children >= k){
                res = mid;
                st = mid + 1;
            }
            else{
                end = mid-1;
            }
        }
        return res;
    }
};