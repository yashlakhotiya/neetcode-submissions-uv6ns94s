class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        if(n == 2) return {0,1};
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v); adj[v].push_back(u);
            indegree[u]++; indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 1) q.push(i);
        }
        int cnt = n;
        while(!q.empty()) {
            int qsize = q.size();
            for(int i=0; i<qsize; i++) {
                int curr = q.front(); q.pop();
                for(int u: adj[curr]) {
                    indegree[u]--;
                    if(indegree[u] == 1) q.push(u);
                }
            }
            cnt -= qsize;
            if(cnt <= 2) break;
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()); q.pop();
        }
        return res;
    }
};