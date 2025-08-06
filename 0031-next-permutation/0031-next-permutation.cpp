class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //index initially -1;
        int idx = -1;
        //iterate it from backside jb tk ki hame koi break point nhi milta like maxima ya minima
        for(int i = n-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        //ydi vha koi break point nhi hoga toh value as it is rah jaegi, idx = -1
        if(idx == -1){
            //reverse kr denge bcz like {3,2,1} next permutation is {1, 2,3}.
            reverse(nums.begin(), nums.end());
            return;
        }
        //ab like {2, 1, 5, 4,3 0, 0} me 3 or 4 ko sawp kr denge
        for(int i = n-1; i>=idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // Step 4: Reverse the tail to get the next permutation
        reverse(nums.begin()+idx+1, nums.end());
        
    }
};