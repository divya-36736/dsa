class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>m;
        m[0] = 1;
        int oddcount = 0;
        int res = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 1) oddcount++;
            if(m.find(oddcount-k) != m.end()){
                res += m[oddcount - k];
            }
            m[oddcount]++;
        }
        return res;
    }
};