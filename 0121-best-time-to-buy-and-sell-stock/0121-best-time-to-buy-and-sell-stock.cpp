class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int minprice = prices[0];
        for(int i = 0; i<n; i++){
            if(minprice > prices[i]){
                minprice = prices[i];
            }
            int pf = prices[i] - minprice;
            maxi = max(maxi, pf);
        }
        return maxi;
    }
};