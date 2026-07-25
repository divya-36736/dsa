class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        int tot = 0;
        int cnt = 0;
        for(int i: nums){
            tot += i;
            if(mp.find(tot-k) != mp.end()){
                cnt += mp[tot-k];
            }
            mp[tot]++;
        }
        return cnt;
    }
};