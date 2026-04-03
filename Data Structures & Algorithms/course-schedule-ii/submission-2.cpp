class Solution {
public:
    bool dfs(vector<int> adj[], int u, vector<int> &res, vector<int> &visited) {
        if(visited[u] == 1) return true; // cycle present;
        if(visited[u] == 2) return false;
        visited[u] = 1;
        for(int n: adj[u]) {
            if(dfs(adj, n, res, visited)) return true;
        }
        visited[u] = 2;
        res.push_back(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0); // 0 : nv, 1 : ip, 2 : visited
        vector<int> adj[numCourses];
        for(auto &p: prerequisites) {
            adj[p[0]].push_back(p[1]);
        }
        vector<int> res;
        for(int i=0; i<numCourses; i++) {
            if(visited[i] == 0 && dfs(adj, i, res, visited)) return {};
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};
