class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        unordered_set<int>us(nums.begin(), nums.end());
        for(int i = 1; i<=n; i++){
            //to check the element is present or not
            if(us.find(i) == us.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};