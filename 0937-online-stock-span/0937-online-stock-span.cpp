class StockSpanner {
public:
    vector<int> prices;   // Move outside to retain state
    stack<int> st;
    
    StockSpanner() {
        // Constructor: nothing needed
    }
    
    int next(int price) {
        prices.push_back(price);  // Add current price
        int i = prices.size() - 1;  // Current index

        // Pop all smaller or equal prices
        while(!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        // Calculate span
        int span = st.empty() ? i + 1 : i - st.top();

        // Push current index to stack
        st.push(i);

        return span;
    }
};
