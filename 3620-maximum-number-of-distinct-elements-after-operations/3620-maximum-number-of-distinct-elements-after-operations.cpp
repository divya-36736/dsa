class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        //create intervals
        vector<pair<long long, long long>>intervals;
        for(long long x:nums){
            intervals.push_back({x-k, x+k});
        }
        //sort by starting position
        sort(intervals.begin(), intervals.end());
        long long current = LLONG_MIN; //
        int distinct = 0;
        
        //greedy approach
        for(auto &[L, R]:intervals){
            if(current < L) current = L; //jump to start of the interval
            if(current <= R){
                distinct++;
                current++;
            }
        }
        return distinct;
    }
};