class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        long long ans  = numBottles;
        int cnt = 0;
        while(numBottles>=numExchange){
            int cnt1 = numBottles/numExchange;
            ans += cnt1;
            cnt = numBottles%numExchange;
            numBottles = cnt + cnt1;
        }
        return (int)ans;
    }
};