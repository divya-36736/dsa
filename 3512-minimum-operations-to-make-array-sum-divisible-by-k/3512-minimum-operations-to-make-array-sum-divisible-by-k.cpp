class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int n = nums.size();
       int cnt = 0;
       int sum = 0;
       for(int i = 0; i<n; i++){
        sum += nums[i];
       } 
       if(sum % k == 0) return cnt;
       while(sum%k!=0){
        sum -= 1;
        cnt++;
       }
       return cnt;
    }
};