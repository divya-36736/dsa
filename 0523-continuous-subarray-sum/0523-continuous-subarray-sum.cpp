class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //if we do the prefix sum and if (prefixsum[j]-prefixsum[i])%k == 0
        //means prefixsum[j]%k = prefixsum[i]%k means remainder equal this we can done via if we store the remainder in map and if we check that same remainder exist in map then it give true othervise give false' 
        int n = nums.size();
        unordered_map<int, int>m;
        m[0] = -1; //this is bcz if 35%7 = 0 but it is not in maap then it give false , but this is valid then it is
        int prefix = 0;
        for(int i =0; i<n; i++){
            prefix += nums[i];
            int rem = prefix%k;
            if(m.find(rem) != m.end()){
                if (i - m[rem] >= 2)
                    return true;
            }else{
                m[rem] = i;
            }
        }
        return false;
    }
};