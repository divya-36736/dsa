class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles; //initially itni toh piyega hi
        //empty bottles 10 hogi
        while(numBottles>=numExchange){
            int rem = numBottles-numExchange;
            numExchange++;
            int cnt = 1;
            while(rem>=numExchange){
                rem = rem-numExchange;
                numExchange++;
                cnt++;
            }
            numBottles = rem+cnt;
            ans += cnt;
        }
        return ans;
    }
};