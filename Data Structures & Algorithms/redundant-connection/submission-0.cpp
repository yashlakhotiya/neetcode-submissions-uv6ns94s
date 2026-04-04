class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];
        vector<int> indegree(n+1, 0);
        queue<int> q;
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[1]]++;
            indegree[e[0]]++;
        }
        for(int i=1; i<n+1; i++) {
            if(indegree[i] <= 1) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: adj[u]) {
                indegree[v]--;
                if(indegree[v] == 1) q.push(v);
            }
        }
        for(auto it = edges.rbegin(); it != edges.rend(); it++) {
            if(indegree[(*it)[0]] > 1 && indegree[(*it)[1]] > 1) return (*it);
        }
        return {};
    }
};
