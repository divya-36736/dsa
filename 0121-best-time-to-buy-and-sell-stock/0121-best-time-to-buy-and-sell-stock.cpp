class Solution {
public: 
    int solve(int i, int hold, int cap, vector<int>& prices,vector<vector<vector<int>>>&dp) {
        int n = prices.size();
        if (i == n || cap == 0) return 0; // stop if no days left or no transactions left
        if(dp[i][hold][cap] != -1)return dp[i][hold][cap];
        if (hold == 0) {
            // option to buy or skip
            int buy  = -prices[i] + solve(i + 1, 1, cap, prices, dp);
            int skip = solve(i + 1, 0, cap, prices, dp);
            return dp[i][hold][cap]=max(buy, skip);
        } else {
            // option to sell (uses up the one transaction) or skip
            int sell =  prices[i] + solve(i + 1, 0, cap - 1, prices, dp);
            int skip =  solve(i + 1, 1, cap, prices, dp);
            return dp[i][hold][cap]=max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(0, 0, 1, prices, dp); // 1 transaction allowed
    }
};



// class Solution {
// public: 
//     int solve(int i,int hold, vector<int>&prices){
//         int n = prices.size();
//         if(i == n) return 0;
//         if(hold == 0){//ydi aaj buy kr liya hai toh canbuy false ho 
//         //jaega kyuki aage buy nhi krsakati aur mene skip kr 
//         //diysa hai buy nhi kiya hai toh main buy kr sakati hu
//             int buy = -prices[i]+solve(i+1, 1, prices); 
//             int skip = solve(i+1, 0, prices);
//             return max(buy, skip);
//         }
//         else{
//             //sell akip
//             int sell = prices[i]+solve(i+1, 0, prices);
//             int skip = solve(i+1, 1, prices);
//             return max(sell, skip);
//         }

//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // int maxi = 0;
//         // int minprice = prices[0];
//         // for(int i = 0; i<n; i++){
//         //     if(minprice > prices[i]){
//         //         minprice = prices[i];
//         //     }
//         //     int pf = prices[i] - minprice;
//         //     maxi = max(maxi, pf);
//         // }
//         // return maxi;

//         //maximun difference of all elements of array
//         // int maxi = 0;
//         // for(int i = 0; i<n; i++){
//         //     for(int j = i+1; j<n; j++){
//         //         maxi = max(maxi, prices[j] - prices[i]);
//         //     }
//         // }
//         // return maxi;
        
//         return solve(0,0, prices);
//     }
// };