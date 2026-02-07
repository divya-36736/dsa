class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        //if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        int maxlen = 1;
        int j = 0;
        for(int i = 0; i<n; i++){
            while(j < n && (nums[j] <= (long long)nums[i]*k)){
                j++;
            }
            maxlen = max(maxlen, j-i);
        }
        return n-maxlen;
    }
};