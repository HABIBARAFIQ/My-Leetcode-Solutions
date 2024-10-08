class StockSpanner {
private:
    stack<pair<int, int>> st;  // Pair of {price, span}
    
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;  // Initialize span as 1 for the current day
        
        // While there are prices in the stack smaller than or equal to the current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Add the span of that price to the current span
            st.pop();  // Remove the smaller price
        }
        
        // Push the current price and its span to the stack
        st.push({price, span});
        
        // Return the span of the current price
        return span;
    }
};
