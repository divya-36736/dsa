class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int>freq;

        for(int x: nums){
            int mod = ((x % value)+value) % value;
            freq[mod]++;
        }
        int ans = 0;
        while(true){
            int mod = ans%value;
            if(freq[mod] == 0) return ans;
            freq[mod]--;
            ans++;
        }
    }
};