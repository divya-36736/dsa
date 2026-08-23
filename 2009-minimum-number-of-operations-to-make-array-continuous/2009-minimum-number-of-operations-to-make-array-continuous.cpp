class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int>arr;
        for(int &x:nums){
            if(arr.empty() || arr.back() != x){
                arr.push_back(x);
            }
        }
        int ans = n;
        for(int i = 0; i<arr.size(); i++){
            int st = arr[i];
            int end = st+n-1;
            
            auto it = upper_bound(arr.begin(), arr.end(), end);
            int j = it-arr.begin();
            int win = j-i;
            ans = min(ans, n-win);
        }
        return ans;
    }
};