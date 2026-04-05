class Solution {
public:
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
            string u = qu[0], v = qu[1];
            if(!adj.count(u) || !adj.count(v)) {
                res.push_back(-1.0);
                continue;
            }
            queue<pair<string,double>> q;
            unordered_set<string> visited;
            q.push({u,1.0});
            visited.insert(u);
            bool found = false;
            while(!q.empty()) {
                auto &[curr, currwt] = q.front(); q.pop();
                visited.insert(curr);
                if(curr == v) {
                    res.push_back(currwt);
                    found = true;
                    break;
                }
                for(auto &[node, wt]: adj[curr]) {
                    if(!visited.count(node)) {
                        q.push({node, wt*currwt});
                    }
                }
            }
            if(!found) res.push_back(-1.0);
        }
        return res;
    }
};