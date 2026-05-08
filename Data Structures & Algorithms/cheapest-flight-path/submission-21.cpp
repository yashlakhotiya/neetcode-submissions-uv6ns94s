class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n, 1e9);
        price[src] = 0;
        for(int iter=1; iter<=k+1; iter++) {
            vector<int> tempprice = price;
            for(auto &flight: flights) {
                int s = flight[0], d = flight[1], cost = flight[2];
                if(price[s] != 1e9 && price[s] + cost < tempprice[d]) tempprice[d] = price[s]+cost;
            }
            price = tempprice;
        }
        return price[dst]==1e9?-1:price[dst];
    }
};
