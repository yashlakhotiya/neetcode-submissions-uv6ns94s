class Solution {
public:
    bool cyclepresent(vector<int> adj[], int u, int p, vector<bool> &visited) {
        if(visited[u]) return true;
        visited[u] = true;
        for(int n: adj[u]) {
            if(n != p && cyclepresent(adj, n, u, visited)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<int> adj[n];
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!visited[0] && cyclepresent(adj, 0, -1, visited)) return false;
        for(int i=0;i<n;i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
};
