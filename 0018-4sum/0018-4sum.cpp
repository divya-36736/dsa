class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                set<int> hashset;

                for (int k = j + 1; k < n; k++) {

                    long long four =
                        (long long)target - nums[i] - nums[j] - nums[k];

                    if (four >= INT_MIN && four <= INT_MAX && hashset.find((int)four) != hashset.end()) {

                        vector<int> temp = {nums[i], nums[j], nums[k], (int)four};

                        sort(temp.begin(), temp.end());

                        ans.insert(temp);
                    }

                    hashset.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};