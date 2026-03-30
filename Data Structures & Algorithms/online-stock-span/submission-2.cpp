class StockSpanner {
    stack<pair<int,int>> s;
    int ind;
public:
    StockSpanner() {
        ind=-1;
    }
    
    int next(int price) {
        ind++;
        while(!s.empty() && s.top().first <= price) {
            s.pop();
        }
        int pgIndex = -1;
        if(!s.empty()) pgIndex = s.top().second;
        s.push({price, ind});
        return ind-pgIndex;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */