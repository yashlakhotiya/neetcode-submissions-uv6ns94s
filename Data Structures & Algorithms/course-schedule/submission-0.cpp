class Solution {
public:
    bool cyclePresent(vector<vector<int>>& adj, int i, vector<bool> &visited) {
        if(visited[i]) return true;
        if(adj[i].empty()) return false;
        visited[i] = true;
        for(auto n: adj[i]) {
            if(cyclePresent(adj, n, visited)) return true;
        }
        adj[i] = {};
        visited[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited(numCourses, false);
        for(int i=0; i<numCourses; i++) {
            if(cyclePresent(adj, i, visited)) return false;
        }
        return true;
    }
};
