class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        if(n == 1) return true;
        for(auto num: nums){
            mp[num]++;
        }
        int st = 0;
        int end = n-1;
        int mid = st+(end-st)/2;
        if(mp[nums[mid]] >=2){
            return false;
        }
        return true;
    }
};