class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int maxi = INT_MIN;
        for(auto it:trips){
            maxi = max(maxi, it[2]);
        }
        vector<int>diff(maxi, 0);
        for(auto it : trips){
            int pass = it[0];
            int from = it[1];
            int to = it[2];

            diff[from] += pass;
            if(to < maxi){
                diff[to] -= pass;
            }
        }
        if(diff[0] > capacity) return false;
        for(int i =1; i<maxi; i++){
            diff[i] = diff[i-1] + diff[i];
            if(diff[i] > capacity) return false;
        }
        return true;
    }
};