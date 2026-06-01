class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n<=1) return cost[0];
        if(n<=2) return cost[0]+cost[1];

        sort(cost.begin(), cost.end());
        int c = 0;

        int i = n-1;
        int cnt  = 0;
        while(i>=0){
            if(cnt < 2){
                c += cost[i];
                cnt++;
                i--;
            }
            else{
                i--;
                cnt  = 0;
            }
        }
        return c;
    }
};