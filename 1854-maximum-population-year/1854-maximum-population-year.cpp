class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int>diff(2051, 0);
        for(auto it: logs){
            int birth = it[0];
            int death = it[1];

            diff[birth] += 1;
            diff[death] -= 1;
        }
        int maxpop = 0;
        int currpop = 0;
        int year = 1950;
        for(int i = 1950; i<=2050; i++){
            currpop += diff[i];
            if(currpop > maxpop){
                maxpop = currpop;
                year = i;
            }
        }
        return year;
    }
};