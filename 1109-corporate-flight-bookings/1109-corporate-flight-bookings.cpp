class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n, 0);
        for(auto it : bookings){
            int l = it[0] - 1;
            int r = it[1] - 1;
            int reserved = it[2];
            diff[l] += reserved;
            if(r+1 < n){
                diff[r+1] -= reserved;
            }
        }

        for(int i = 1; i<n; i++){
            diff[i] = diff[i-1]+diff[i];
        }
        return diff;
    }
};