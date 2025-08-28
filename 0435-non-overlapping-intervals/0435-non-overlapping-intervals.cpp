class Solution {
public:
    static bool cmpr(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // sort by end time
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt  = 1;
        sort(intervals.begin(), intervals.end(), cmpr);
        int lastEnd = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= lastEnd){
                cnt++;
                lastEnd = intervals[i][1];
            }
        }
        return n-cnt;
    }
};