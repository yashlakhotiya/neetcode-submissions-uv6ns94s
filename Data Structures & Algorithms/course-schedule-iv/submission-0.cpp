class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(auto &e: prerequisites) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        unordered_set<int> adjprereq[n];
        for(int i=0; i<n; i++) {
            if(!indegree[i]) q.push(i);
            adjprereq[i].insert(i);
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int n: adj[u]) {
                adjprereq[n].insert(adjprereq[u].begin(), adjprereq[u].end());
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        vector<bool> res;
        for(auto &q: queries) {
            res.push_back(adjprereq[q[1]].count(q[0])?true:false);
        }
        return res;
    }
};