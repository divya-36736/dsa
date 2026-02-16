class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }
        //frq of freq
         unordered_map<int,int> freqCount;
        for(auto &it : freq){
            freqCount[it.second]++;
        }
        
        for(int num : nums){
            if(freqCount[freq[num]] == 1){
                return num;
            }
        }
        return -1;
    }
};