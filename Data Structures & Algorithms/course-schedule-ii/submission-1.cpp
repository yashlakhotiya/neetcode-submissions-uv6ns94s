class Solution {
public:
    stack<int> stk;
    bool dfs(vector<int> adj[], int i, vector<bool> &visited) {
        if(visited[i]) return true;
        visited[i] = true;

        for(int n: adj[i]) {
            if(dfs(adj, n, visited)) return true;
        }

        stk.push(i);
        visited[i] = false;
        adj[i] = {};
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto &pre: prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<bool> visited(numCourses, false);
        for(int i=0; i<numCourses; i++) {
            if(!visited[i] && dfs(adj, i, visited)) return {};
        }
        vector<int> res;
        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
