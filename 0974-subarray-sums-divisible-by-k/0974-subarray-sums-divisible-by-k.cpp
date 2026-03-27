class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>m;
        m[0] = 1;
        int prefix = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            prefix += nums[i];
            int rem = ((prefix % k)+k)%k;
            if(m.find(rem) != m.end()){
                cnt += m[rem];
            }
            m[rem]++;
        }
        return cnt;
    }
};