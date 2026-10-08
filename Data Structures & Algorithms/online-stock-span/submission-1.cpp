class StockSpanner {
    stack<int> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int days = 1;
        if(st.empty()){
            st.push(price);
        } else {
            vector<int> temp;
            while(!st.empty() && st.top() <= price){
                days++;
                temp.push_back(st.top());
                st.pop();
            }
            while(!temp.empty()){
                st.push(temp.back());
                temp.pop_back();
            }
            st.push(price);
        }

        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */