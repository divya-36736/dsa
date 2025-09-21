class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int t = timeSeries.size();
        int cnt  = 0;
        for(int i = 1; i<t; i++){
            //overlaping conditoin
            cnt += min(duration, timeSeries[i]-timeSeries[i-1]);
        }
        cnt += duration;
        return cnt;
    }
};