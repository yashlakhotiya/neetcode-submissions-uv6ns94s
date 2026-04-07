class Solution {
public:
    void dfs(vector<pair<int,int>> adj[], int curr, int t, vector<int> &time) {
        if(t >= time[curr]) return;
        time[curr] = t;
        for(auto &[node, weight]: adj[curr]) {
            dfs(adj, node, t+weight, time);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto &v: times) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        vector<int> dist(n+1, 1e9);
        dfs(adj, k, 0, dist);
        int res = *max_element(dist.begin()+1, dist.end());
        return res==1e9?-1:res;
    }
};