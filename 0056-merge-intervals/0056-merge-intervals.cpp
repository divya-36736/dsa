class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        //in this we need to check all iteration
        // vector<vector<int>>res;
        
        // if(n == 0) return res;

        // vector<int>tempInt = intervals[0]; //1st push

        // for(auto it: intervals){
        //     if(it[0] <= tempInt[1]){ //
        //         tempInt[1] = max(it[1], tempInt[1]);
        //     }else{
        //         res.push_back(tempInt);
        //         tempInt = it;
        //     }
        // }
        // res.push_back(tempInt);
        // return res;

        //2nd
        vector<vector<int>>res;
        int i = 0;

        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // ✅ Merge all overlapping intervals
            while (i + 1 < n && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }

            res.push_back({start, end});
            i++;
        }

        return res;
    }
};