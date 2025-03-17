class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> b;
        vector<int> v;
        int n = nums.size();

        if (n % 2 != 0) {
            return false;
        }

        sort(nums.begin(), nums.end()); // Sorting ensures equal elements are adjacent

        int st = 0;
        while (st < n) {
            if (st + 1 < n && nums[st] == nums[st + 1]) {
                v.push_back(nums[st]);
                st += 2; // Move to the next pair
            } else {
                return false;
            }
        }

        return true;
    }
};
