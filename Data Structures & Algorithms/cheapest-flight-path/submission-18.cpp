class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &f: flights) {
            int u=f[0], v=f[1], w=f[2];
            adj[u].push_back({v,w});
        }
        int steps = 1;
        queue<pair<int,int>> q;
        q.push({src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            int qsize = q.size();
            if(steps >= k+2) break;
            while(qsize--) {
                auto [node, curcost] = q.front(); q.pop();
                if(node == dst){
                    continue;
                }
                for(auto [n,w]: adj[node]) {
                    if(curcost+w < dist[n]) {
                        dist[n] = curcost+w;
                        q.push({n, dist[n]});
                    }
                }
            }
            steps++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
