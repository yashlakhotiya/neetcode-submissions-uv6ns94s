class Solution {
public:
    bool hasCycle(vector<vector<int>> &adj, int currNode, int parent, vector<bool> &visited, int &count) {
        visited[currNode] = true;
        count++;
        for(auto neigh: adj[currNode]) {
            if(neigh == parent) {
                continue;
            }
            if(visited[neigh]) {
                return true;
            }
            if(hasCycle(adj, neigh, currNode, visited, count)) {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = vector<vector<int>>(n);
        for(auto edge: edges) {
            int v0 = edge[0];
            int v1 = edge[1];
            adj[v0].push_back(v1);
            adj[v1].push_back(v0);
        }
        vector<bool> visited = vector<bool>(n, false);
        int count = 0;
        if(hasCycle(adj, 0, -1, visited, count) || count != n) {
            return false;
        }
        return true;
    }
};
