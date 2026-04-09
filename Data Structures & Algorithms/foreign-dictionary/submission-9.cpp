class Solution {
public:
    bool topo(string &res, char c, unordered_map<char, vector<char>> &adj, unordered_set<char> &visited, unordered_set<char> &visiting) {
        if(visiting.count(c)) return false;
        visiting.insert(c);
        for(char n: adj[c]) {
            if(visited.count(n)) continue;
            if(!topo(res, n, adj, visited, visiting)) return false;
        }
        res.push_back(c);
        visited.insert(c);
        visiting.erase(c);
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_set<char> allChars;
        for(auto &word: words) {
            for(char c: word) allChars.insert(c);
        }
        for(int k=1; k<words.size(); k++) {
            string prev = words[k-1];
            string curr = words[k];
            if(prev.size() > curr.size() && prev.starts_with(curr)) return "";
            if(prev.size() < curr.size() && curr.starts_with(prev)) continue;
            for(int i=0; i<min(prev.size(), curr.size()); i++) {
                if(prev[i] != curr[i]) {
                    adj[prev[i]].push_back(curr[i]);
                    break;
                }
            }
        }
        string res = "";
        unordered_set<char> visited;
        unordered_set<char> visiting;
        for(char c: allChars) {
            if(!visited.count(c)) {
                if(!topo(res, c, adj, visited, visiting)) return "";
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
