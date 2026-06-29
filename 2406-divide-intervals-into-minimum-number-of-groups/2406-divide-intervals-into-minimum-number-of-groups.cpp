class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>start;
        vector<int>endin;
        for(auto it:intervals){
            start.push_back(it[0]);
            endin.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(endin.begin(), endin.end());
        int grp = 0;
        int endptr = 0;
        for(auto &it:start){
            if(it>endin[endptr]){
                endptr++;
            }else{
                grp++;
            }
        }
        return grp;
    }
};