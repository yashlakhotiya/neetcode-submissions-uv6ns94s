class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string,double>>> &adj, string curr, string target, double currwt, unordered_set<string> &visited) {
        if(curr == target) return currwt;
        visited.insert(curr);
        for(auto &[node, wt]: adj[curr]) {
            if(!visited.count(node)) {
                double ans = dfs(adj, node, target, wt*currwt, visited);
                if(ans != -1.0) return ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i=0; i<n; i++) {
            string u = equations[i][0], v = equations[i][1];
            double wt = values[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, 1.0/wt});
        }
        vector<double> res;
        for(auto &qu: queries) {
            unordered_set<string> visited;
            string u = qu[0], v = qu[1];
            if(!adj.count(u) || !adj.count(v)) {
                res.push_back(-1.0);
                continue;
            }
            res.push_back(dfs(adj, u, v, 1, visited));
        }
        return res;
    }
};