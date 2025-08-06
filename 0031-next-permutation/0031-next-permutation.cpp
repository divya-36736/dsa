class Solution {
public:
    // void solve(int i, vector<int>& nums, vector<vector<int>>& ans) {
    //     if (i == nums.size()) {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     for (int idx = i; idx < nums.size(); idx++) {
    //         swap(nums[i], nums[idx]);
    //         solve(i + 1, nums, ans);
    //         swap(nums[i], nums[idx]);
    //     }
    // }
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        //by buit-in function
        next_permutation(nums.begin(), nums.end());
        // vector<vector<int>> ans;
        // solve(0, nums, ans);
        // // sort this ans;
        // sort(ans.begin(), ans.end());
        // // Find the next permutation
        // bool found = false;
        // for (int i = 0; i < ans.size(); i++) {
        //     if (ans[i] == nums) {
        //         // If it's not the last one
        //         if (i + 1 < ans.size()) {
        //             nums = ans[i + 1];
        //         } else {
        //             // If it is the last permutation, wrap around to first
        //             nums = ans[0];
        //         }
        //         found = true;
        //         break;
        //     }
        // } //int his code we need to add a set bcz there is more dublicates
        // int n = nums.size();
        // //index initially -1;
        // int idx = -1;
        // //iterate it from backside jb tk ki hame koi break point nhi milta
        // like maxima ya minima for(int i = n-2; i>= 0; i--){
        //     if(nums[i] < nums[i+1]){
        //         idx = i;
        //         break;
        //     }
        // }
        // //ydi vha koi break point nhi hoga toh value as it is rah jaegi, idx
        // = -1 if(idx == -1){
        //     //reverse kr denge bcz like {3,2,1} next permutation is {1, 2,3}.
        //     reverse(nums.begin(), nums.end());
        //     return;
        // }
        // //ab like {2, 1, 5, 4,3 0, 0} me 3 or 4 ko sawp kr denge
        // for(int i = n-1; i>=idx; i--){
        //     if(nums[i] > nums[idx]){
        //         swap(nums[i], nums[idx]);
        //         break;
        //     }
        // }
        // // Step 4: Reverse the tail to get the next permutation
        // reverse(nums.begin()+idx+1, nums.end());
    }
};