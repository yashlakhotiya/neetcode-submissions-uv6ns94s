class Solution {
public:
    bool canFinish(int i, vector<int> adj[], vector<int> &visited) {
        visited[i] = 1;
        for(int n: adj[i]) {
            if(visited[n] == 1) return false;
            if(visited[n] == 0 && !canFinish(n, adj, visited)) return false;
        }
        visited[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto &p: prerequisites) {
            int from = p[1], to = p[0];
            adj[from].push_back(to);
        }
        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(visited[i]==0 && !canFinish(i, adj, visited)) return false;
        }
        return true;
    }
};
