class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for(auto &p: prerequisites){
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            cnt++;
            for(int n: adj[top]) {
                indegree[n]--;
                if(indegree[n] == 0) {
                    q.push(n);
                }
            }
        }
        if(cnt != numCourses) return false;
        return true;
    }
};
