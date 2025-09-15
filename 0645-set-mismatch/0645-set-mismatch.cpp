class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        // Count occurrences of each number
        for(int num : nums) {
            freq[num]++;
        }

        int dup = -1, missing = -1;
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2) dup = i;
            if(freq[i] == 0) missing = i;
        }

        return {dup, missing};
    }
};
