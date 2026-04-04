class Solution {
public:
    int height(vector<int> adj[], int root, vector<bool> &visited) {
        if(adj[root].size() == 0) return 0;
        visited[root] = true;
        int maxheight = INT_MIN;
        for(int n: adj[root]) {
            if(!visited[n]) {
                int h = height(adj, n, visited);
                if(h > maxheight) {
                    maxheight = h;
                }
            }
        }
        return 1+maxheight;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        vector<int> minres;
        int minheight = INT_MAX;
        for(int i=0; i<n; i++) {
            vector<bool> visited(n, false);
            int h=height(adj, i, visited);
            if(h < minheight) {
                minheight = h;
                minres = {i};
            } else if(h == minheight) {
                minres.push_back(i);
            }
        }
        return minres;
    }
};