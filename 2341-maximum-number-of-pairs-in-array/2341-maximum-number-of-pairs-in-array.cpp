class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int pair = 0;
        int ans = 0;
        for (auto it : mp) {
            if(it.second > 0){
                pair += it.second/2;
                ans += it.second%2;
            }
        }
        return {pair, ans};
    }
};