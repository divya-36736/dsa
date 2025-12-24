class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxi = INT_MIN;
        int best = values[0]; //values[i]+i;
        for(int j = 1; j<n; j++){
            maxi = max(maxi, best+values[j]-j);
            best = max(best, values[j]+j);
        }
        return maxi;
    }
};