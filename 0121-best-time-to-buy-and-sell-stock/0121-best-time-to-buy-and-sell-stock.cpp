class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //int maxi = 0;
        // int minPrice = prices[0];

        // for(int i = 0; i<n; i++){
        //     if(prices[i] < minPrice){
        //         minPrice = prices[i];
                    
        //         }
        //         int pr = prices[i] - minPrice;
        //         maxi = max(pr, maxi);
        // }
        // return maxi;


        //optimal approach
        int maxi = 0;
        int mini = INT_MAX;
        for(int i =  0; i<n; i++){
            mini = min(prices[i], mini);
            int pr = prices[i] - mini;
            maxi = max(maxi, pr);
        } 
        return maxi;
    }
};