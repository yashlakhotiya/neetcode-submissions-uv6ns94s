class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &f: flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int,int>> q;
        q.push({src, 0});
        int flightstaken = 0;
        int requiredFlights = k+1;
        while(!q.empty() && flightstaken < requiredFlights) {
            int size = q.size();
            while(size--) {
                auto p = q.front(); q.pop();
                int node = p.first, costtoreachcurrnode = p.second;
                for(auto &neigh: adj[node]) {
                    if(costtoreachcurrnode+neigh.second < dist[neigh.first]) {
                        dist[neigh.first] = costtoreachcurrnode+neigh.second;
                        q.push({neigh.first, dist[neigh.first]});
                    }
                }
            }
            flightstaken++;
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};
