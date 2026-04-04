class Solution {
public:
    bool checkValidTree(int u, int p, vector<bool> &visited, vector<int> adj[]) {
        if(visited[u]) return false;
        visited[u] = true;
        for(int n : adj[u]) {
            if(n != p && !checkValidTree(n, u, visited, adj)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!checkValidTree(0, -1, visited, adj)) return false;
        for(int i=0; i<n; i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
};
