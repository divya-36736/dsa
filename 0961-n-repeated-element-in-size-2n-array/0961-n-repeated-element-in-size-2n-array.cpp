class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        } 
        for(auto it: mp){
            if(it.second == n/2){
                ans = it.first;
            }
        }
        return ans;
    }
};