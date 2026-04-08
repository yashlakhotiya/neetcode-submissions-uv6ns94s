class Solution {
public:
    bool dfs(unordered_map<string, vector<string>> &adj, vector<string> &res, string curr, int n) {
        if(res.size()==n) return true;
        if(adj[curr].empty()) return false;
        vector<string> temp = adj[curr];
        for(int i=0; i<temp.size(); i++) {
            string v = temp[i];
            adj[curr].erase(adj[curr].begin()+i);
            res.push_back(v);
            if(dfs(adj, res, v,n)) return true;
            adj[curr].insert(adj[curr].begin()+i, v);
            res.pop_back();
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string>> adj;
        for(auto &t: tickets) {
            adj[t[0]].push_back(t[1]);
        }
        vector<string> res = {"JFK"};
        dfs(adj, res, "JFK", tickets.size()+1);
        return res;
    } 
};
