class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        // Remove consecutive duplicates
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1])
                arr.push_back(nums[i]);
        }

        // Count hills and valleys in cleaned array
        for(int j = 1; j < arr.size() - 1; j++) {
            if(arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) {
                cnt++; // Hill
            } else if(arr[j] < arr[j - 1] && arr[j] < arr[j + 1]) {
                cnt++; // Valley
            }
        }

        return cnt;
    }
};
