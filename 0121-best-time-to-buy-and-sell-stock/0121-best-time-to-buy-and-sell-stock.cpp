class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minprice = INT_MAX;
        int maxprice = 0;
        for(int price:prices){
            if(price<minprice){
                minprice = price;
            }
            else{
                maxprice = max(maxprice, price-minprice);
            }
        }
        return maxprice;
    }
};