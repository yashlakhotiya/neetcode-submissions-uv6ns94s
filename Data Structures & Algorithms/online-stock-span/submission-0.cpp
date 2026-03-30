class StockSpanner {
    int ind;
    stack<pair<int,int>> s;
public:
    StockSpanner() {
       ind=-1;
    }
    
    int next(int price) {
        ind++;
        while(!s.empty() && price >= s.top().first) {
            s.pop();
        }
        int ans = ind-(s.empty()?-1:s.top().second);
        s.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */