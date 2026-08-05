class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(), nums.end());
        set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        int x = nums[0];
        while(x<=nums[n-1]){
            if(!st.count(x)){
                ans.push_back(x);
            }
            x++;
        }
        return ans;   
    }
};