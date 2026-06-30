class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        int i = 1;
        while(i<n){

            if(i<n && ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int peak = 0;

            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                i++;
                candies += peak;
            }

            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                i++;
                candies += valley;
            }

            candies -= min(valley, peak);
        }
        return candies;
    }
};