class Solution {
public:
    int getdist(int x1, int y1, int x2, int y2) {
        return abs(x1-x2)+abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int,int>>> adj;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = getdist(x1,y1,x2,y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i, dist});
            }
        }

        int res = 0;
        unordered_set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()) {
            auto [cost, point] = pq.top(); pq.pop();
            if(visited.count(point)) continue;
            res += cost;
            visited.insert(point);
            for(auto [newpoint, newcost] : adj[point]) {
                if(!visited.count(newpoint)) {
                    pq.push({newcost, newpoint});
                }
            }
        }
        return res;
    }
};
