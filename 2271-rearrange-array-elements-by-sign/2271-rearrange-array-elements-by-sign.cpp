class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i = 0; i<n; i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
        }
        }
        //pos at even index pr and neg at odd index pr
        for(int j = 0; j<n/2; j++){
            nums[2*j] = pos[j];
            nums[2*j + 1] = neg[j];
        }
        return nums;
    }
};
