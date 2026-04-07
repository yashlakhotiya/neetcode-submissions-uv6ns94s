class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dist(n+1, 1e9);
        pq.push({0,k});
        dist[k] = 0;
        vector<pair<int,int>> adj[n+1];
        for(auto &v: times) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        while(!pq.empty()) {
            auto [curdist, curnode] = pq.top(); pq.pop();
            if(curdist > dist[curnode]) continue;
            for(auto [node, delay]: adj[curnode]) {
                if(curdist+delay < dist[node]) {
                    dist[node] = curdist+delay;
                    pq.push({dist[node], node});
                }
            }
        }
        int maxi = -1;
        for(int i=1; i<=n; i++) {
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
