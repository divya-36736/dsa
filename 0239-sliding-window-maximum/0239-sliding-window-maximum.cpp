class Solution {
public:
    int getMax(vector<int>& nums, int l, int r) {
        int maxi = INT_MIN;
        for (int i = l; i <= r; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        // //brute force approach
        // vector<int>ans;
        // for(int i = 0; i<=n-k; i++){
        //     int maxi = nums[i];
        //     for(int j= i; j<i+k; j++){
        //         maxi = max(maxi, nums[j]);
        //     }
        //     ans.push_back(maxi);

        // }
        // return ans;
        

        // //2 pointer appraoch
        // int l = 0;
        // int r = 0;
        // int maxi = INT_MIN;
        // vector<int>arr;
        // while(r<k-1){
        //     r++;
        // }
        // while(r<nums.size()){
        //     arr.push_back(getMax(nums, l, r));
        //     l++;
        //     r++;
        // }
        // return arr;

        //optimal approach dq use krke
        deque<int>dq;
        vector<int>res;

        //for 1st window
        for(int i = 0; i<k; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //for other window ke liye
        for(int i = k; i<n; i++){
            res.push_back(nums[dq.front()]);

            //remove that not part of curr window
            while(dq.size() && dq.front() <= i-k){
                dq.pop_front();
            }

            //remove smaller values 
            while(!dq.empty() && nums[dq.back()]<= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};