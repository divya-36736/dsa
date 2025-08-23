class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        // 1st we do this sort
        int n = nums.size();
        //  sort(nums.begin(), nums.end());
        //  return nums[n-k];

        // by heap
        priority_queue<int>pq;
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        while(!pq.empty()){
            k--;
            if(k == 0){
                ans =  pq.top();
            }
            pq.pop();
        }
        return ans;
    }
};