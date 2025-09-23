class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]]++;
        }
        int freq = 0;
        int cnt = 0;
        for(auto it: mpp){
            int first = it.first;
            int second = it.second;
            freq = max(freq, second);
        }
        for(auto it: mpp){
            if(it.second == freq){
                cnt++;
            }
        }
        return freq*cnt;
    }
};