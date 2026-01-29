class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int add = additionalRocks;
        vector<int>diff(n);
        for(int i = 0; i<n; i++){
            diff[i] = capacity[i] - rocks[i];
        }
        int ans = 0;
        //sort for smalles additional required rock for full capacity
        sort(diff.begin(), diff.end());
        for(int i = 0; i<n; i++){
            if(diff[i] <= add){
                ans++;
                add = add-diff[i];
            }
        }
        return ans;
    }
};