class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end());
        if(n == 0) return res;

        vector<int>tempInt = intervals[0]; //1st push
        for(auto it: intervals){
            if(it[0] <= tempInt[1]){
                tempInt[1] = max(it[1], tempInt[1]);
            }else{
                res.push_back(tempInt);
                tempInt = it;
            }
        }
        res.push_back(tempInt);
        return res;
    }
};