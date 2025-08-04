class Solution {
public:
    //void getperms(vector<int>&nums, int idx, vector<vector<int>> &ans){

        // int n = nums.size();
        // if(idx == n){
        //     ans.push_back({nums});
        //     return;
        // }
        // for(int i = idx; i<n; i++){
        //     swap(nums[idx], nums[i]);
        //     getperms(nums, idx+1, ans);
        //     swap(nums[idx], nums[i]);
        // }
    //}

    void recurPermute(vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums, vector<int>&freq){
        //base case
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        //hamane array pr travese kiya
        for(int i = 0; i<nums.size(); i++){
            if(!freq[i]){ //phir hmaane check kiya ki , element phaale visisted hai ya nhi, ydi vivited nhi hai toh usko hum ds pe push  kr denge
                ds.push_back(nums[i]);
                //aur ab freq uski 1 kr denge ki visite ho gya
                freq[i] =1;
                //ab next element ke liye call lagaenge
                recurPermute(ds, ans, nums, freq);
                //for back tracking ke liye usko vapish 0 kr denge
                freq[i] = 0;
                ds.pop_back(); //backtracking
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        //store the ds 
        vector<vector<int>>ans;
        //store the all permutatioons
        vector<int>ds;
        //for visisted aur not visites checking or initialize it with 0
        vector<int>freq(n, 0);
        //void funvtion to check and traverse on all elements
        recurPermute(ds, ans, nums, freq);
        // vector<vector<int>> ans;
        // getperms(nums, 0, ans);
        // return ans;
        return ans;
    }
};