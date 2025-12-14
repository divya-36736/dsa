class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            string ans1 = to_string(nums[i]);
            for(int i = 0; i<ans1.size(); i++){
                ans.push_back(ans1[i]-'0');
            }
        }
        return ans;
    }
};