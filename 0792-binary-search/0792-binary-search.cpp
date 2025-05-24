class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int a;
        int st = 0;
        int end = n-1;
        int mid = st + (end-st)/2;
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
               return i;
            }
            
        }
        return -1;
    }
};