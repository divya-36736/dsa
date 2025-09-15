class Solution {
public:
    // int recursive(int i, vector<int>& nums, int mini, int maxi, int len) {
    //     if (i >= nums.size()) {
    //         if (len > 0 && maxi - mini == 1) {
    //             return len;
    //         }
    //         return 0;
    //     }
        
    //     // Option 1: skip current element
    //     int notTake = recursive(i + 1, nums, mini, maxi, len);

    //     // Option 2: take current element
    //     int newMini = (len == 0 ? nums[i] : min(mini, nums[i]));
    //     int newMaxi = (len == 0 ? nums[i] : max(maxi, nums[i]));
    //     int take = recursive(i + 1, nums, newMini, newMaxi, len + 1);

    //     return max(take, notTake);
    // }

    int findLHS(vector<int>& nums) {
        int n = nums.size();
        // return recursive(0, nums, INT_MAX, INT_MIN, 0);
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto &[num, count]:mp){ 
            //if nums and num+1 find then we will consider it
            if(mp.find(num+1) != mp.end()){
                ans = max(ans, count + mp[num + 1]);
            }
        }
        return ans;
    }
};
