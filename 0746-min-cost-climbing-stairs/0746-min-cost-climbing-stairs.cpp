class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int fut1 = 0;
        int fut2 = 0;
        int curr;
        for(int i = n-1; i>=0; i--){
            curr = cost[i]+min(fut1, fut2);
            fut2 = fut1;
            fut1 = curr;
        }
        return min(fut1, fut2);
    }
};