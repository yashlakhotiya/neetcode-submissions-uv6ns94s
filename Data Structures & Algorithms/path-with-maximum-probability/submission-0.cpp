class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++) {
            auto edge = edges[i];
            int start = edge[0];
            int end = edge[1];
            double prob = succProb[i];
            adj[start].push_back({end, prob});
            adj[end].push_back({start, prob});
        }
        vector<double> probabilities(n, 0);
        probabilities[start_node] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            auto [prob, node] = curr;
            if(node == end_node) {
                return prob;
            }
            for(auto neigh: adj[node]) {
                auto [nextnode, nextprob] = neigh;
                if(prob * nextprob > probabilities[nextnode]) {
                    pq.push({prob * nextprob, nextnode});
                    probabilities[nextnode] = prob * nextprob;
                }
            }
        }
        return 0;
    }
};