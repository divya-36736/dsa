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
            if(it.second == 1) ans += 1;
            int cnt = it.second % 2;
            if (cnt != 0 && it.second/2 > 0) {
                pair += (it.second/2);
                ans += 1;
            }else{
                pair += (it.second / 2);
            }
        }
        return {pair, ans};
    }
};