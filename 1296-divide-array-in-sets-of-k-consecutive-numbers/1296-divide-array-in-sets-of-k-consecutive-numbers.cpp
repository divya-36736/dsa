class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();

        if (n % k != 0)
            return false;

        map<int, int> mp;

        for (auto &num : nums) {
            mp[num]++;
        }

        for (auto &it : mp) {

            int ele = it.first;

            while (mp[ele] > 0) {

                mp[ele]--; 

                int curr = ele;

                int cnt = k - 1;

                while (cnt--) {

                    if (mp[curr + 1] <= 0)
                        return false;

                    mp[curr + 1]--;

                    curr++;
                }
            }
        }

        return true;
    }
};