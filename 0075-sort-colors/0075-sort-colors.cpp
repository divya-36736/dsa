class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //sort(nums.begin(), nums.end());
        int mini = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j= i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
};