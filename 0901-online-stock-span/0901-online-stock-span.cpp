class StockSpanner {
public:
    stack<int>st;
    vector<int>stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stock.push_back(price);
        while(!st.empty() && stock[st.top()] <= price){
            st.pop();
        }
        int span = st.empty()? stock.size() : stock.size()-1-st.top();
        st.push(stock.size()-1);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */