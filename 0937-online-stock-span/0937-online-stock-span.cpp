class StockSpanner {
private:
    vector<int>stock;
    stack<int>s;

public:
    StockSpanner() {
        

    }
    
    int next(int price) {
        stock.push_back(price);
        while(!s.empty() && stock[s.top()] <= price){
            s.pop();
        }
        int span = s.empty() ? stock.size() : stock.size() -1- s.top();
        s.push(stock.size()-1);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */