class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //take set bcz set not allow duplicat values
        // set<int> set;
        // int n = nums.size();
        //iterate from 0 to n values for insert the values in set
        // for (int i = 0; i < n; i++) {
        //     set.insert(nums[i]);
        // }
        //set size
        // int k = set.size();
        //we now answer give in nums not in set then the value of set is now inserted in back in nums
        // int j = 0;
        // for (int x : set) {
        //     nums[j++] = x;
        // }
        // return k;

        int n = nums.size();
        int i = 0;
        for(int j = 1; j<n; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};