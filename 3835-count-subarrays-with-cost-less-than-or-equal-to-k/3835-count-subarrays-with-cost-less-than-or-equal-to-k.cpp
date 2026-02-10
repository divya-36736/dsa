class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int j = 0;
        long long ans = 0;
        deque<int>mx,mn;
        for(int i = 0; i<n; i++){
            //max
            while(!mx.empty() && nums[mx.back()] <= nums[i]) mx.pop_back();
            mx.push_back(i);
            //min
            while(!mn.empty() && nums[mn.back()] >= nums[i]) mn.pop_back();
            mn.push_back(i);
            //shrink jaise hi value greater aa gyi
            while(j <= i && (nums[mx.front()] - nums[mn.front()])*1ll * (i-j+1)>k){
                if(mx.front() == j) mx.pop_front();
                if(mn.front() == j) mn.pop_front();
                j++;
            } 
            ans += (i-j+1);
        }
        return ans;
    }
};