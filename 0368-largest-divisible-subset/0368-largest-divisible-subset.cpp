class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        //sort the array so that its cocept same as LIS
        sort(nums.begin(), nums.end());

        //make vector
        vector<int>dp(n, 1); //dp array to store length of the LDS at the index
        vector<int>prev(n, -1); //array to store the prev index to reconstruct

        for(int i =1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]% nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
        }
        //find the index of maximum length
        int maxlen = 0;
        int maxIndex = 0;
        for(int i = 0; i<n; i++){
            if(dp[i] > maxlen){
                maxlen = dp[i];
                maxIndex = i;
            }
        }
        //reconstruct
        vector<int>temp;
        int curr = maxIndex;
        while(curr != -1){
            temp.push_back(nums[curr]);
            curr = prev[curr];
        }
        return temp;
    }
};