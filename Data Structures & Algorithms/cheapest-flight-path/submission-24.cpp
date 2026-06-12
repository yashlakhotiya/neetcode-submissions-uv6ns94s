class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src == dst) return 0;
        vector<vector<int>> adj[n];
        for(auto &f: flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        set<vector<int>> s;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        s.insert({0,-1,src});
        while(!s.empty()) {
            auto v = *s.begin();
            s.erase(s.begin());
            dist[v[2]] = min(dist[v[2]], v[0]);
            if(v[2] == dst) {
                return dist[v[2]];
            }
            if(v[1]>=k) continue;
            for(auto neigh: adj[v[2]]) {
                s.insert({v[0]+neigh[1],v[1]+1,neigh[0]});
            }
        }
        return -1;
    }
};
