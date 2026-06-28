class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int c = capacity.size();
        int r = rocks.size();
        int add = additionalRocks;
        vector<int>diff(c, 0);
        for(int i = 0; i<c; i++){
            diff[i] = capacity[i]-rocks[i];
        }
        int cnt = 0;
        sort(diff.begin(), diff.end());
        for(int i = 0; i<c; i++){
            if(diff[i] == 0){
                cnt++;
                continue;
            }
            if(diff[i] <= add){
                add = add-diff[i];
                cnt++;
            }
        }
        return cnt;
    }
};