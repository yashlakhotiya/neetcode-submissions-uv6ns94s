class Solution {
public:
    void dfs(int u, int p, vector<int> adj[], vector<bool> &visited) {
        if(visited[u]) return;
        visited[u] = true;
        for(int n: adj[u]) {
            if(p != u) {
                dfs(n, u, adj, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> visited(n, false);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, -1, adj, visited);
                cnt++;
            }
        }
        return cnt;
    } 
};
