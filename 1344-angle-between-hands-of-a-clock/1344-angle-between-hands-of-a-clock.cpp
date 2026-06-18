class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = abs(30*hour + 0.5*minutes - 6*minutes);
        if(ans>180) return abs(360-ans);
        return ans;
    }
};