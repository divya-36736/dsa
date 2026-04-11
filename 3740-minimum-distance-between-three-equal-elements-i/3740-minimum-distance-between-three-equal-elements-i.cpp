class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>m;
        for(int i = 0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &[val, idx]: m){
            if(idx.size()<3) continue;
            for (int i = 0; i + 2 < idx.size(); i++) {
                int i1 = idx[i], i2 = idx[i+1], i3 = idx[i+2];
                int dist = abs(i1 - i2) + abs(i2 - i3) + abs(i3 - i1);
                ans = min(ans, dist);
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};