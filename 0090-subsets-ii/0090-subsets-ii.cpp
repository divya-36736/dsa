class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int subsets = 1 << n;

        set<vector<int>> st;

        for(int mask = 0; mask < subsets; mask++) {
            vector<int> res;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i))
                    res.push_back(nums[i]);
            }

            st.insert(res);
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};