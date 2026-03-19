class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int i = 0; i<n; i++){
            freq[nums[i]]++;
        }
        vector<int>sortedUnique;
        for(auto it: freq){
            sortedUnique.push_back(it.first);
        }
        sort(sortedUnique.begin(), sortedUnique.end());
        for(int i = 0; i<sortedUnique.size(); i++){
            for(int j = i+1; j<sortedUnique.size(); j++){
                int x = sortedUnique[i];
                int y = sortedUnique[j];
                if(freq[x] != freq[y]) return {x,y};
            }
        }
        return {-1, -1};
    }
};