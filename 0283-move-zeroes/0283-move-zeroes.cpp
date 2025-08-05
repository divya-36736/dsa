class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //int n = nums.size();
        // vector<int>temp;
        // int nonzero = 0;
        // for(int i = 0; i<n; i++){
        //     if(nums[i] != 0){
        //         nums[nonzero] = nums[i];
        //         nonzero++;
        //     }

        // }
        // for(int i=nonzero; i<n; i++){
        //     nums[i] = 0;
        // }

        // for(int i = 0; i<n; i++){
        //     if(nums[i] != 0){
        //         temp.push_back(nums[i]);
        //     }
        // }
        // int nz = temp.size();
        // for(int i = 0; i<nz; i++){
        //     nums[i] = temp[i];
        // }

        // for(int i = nz; i<n; i++){
        //     nums[i] = 0;
        // }

        //optimal approach;

        // int j = n; 
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == 0) {
        //         j = i; 
        //         break;
        //     }
        // }
        
        // for(int i = j + 1; i < n && j < n; i++) {
        //     if(nums[i] != 0) {
        //         swap(nums[i], nums[j]);
        //         j++;
        //     }
        // }

        int n = nums.size();
        vector<int>temp;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        while(temp.size() != n){
            temp.push_back(0);
        }
        nums = temp;

    };
};