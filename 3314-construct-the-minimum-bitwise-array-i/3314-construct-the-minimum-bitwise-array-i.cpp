class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int num: nums){
            int found = -1;
            for(int i = 1; i<num; i++){
                if(((i) | (i+1)) == num){
                    found = i;
                    break;
                }
            }
            ans.push_back(found);
        }
        return ans;
    }
};