class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       
        vector<vector<int>>ans;
        intervals.push_back({newInterval[0], newInterval[1]});
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i = 0; i<n; i++){
            int st = intervals[i][0];
            int end = intervals[i][1];
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};