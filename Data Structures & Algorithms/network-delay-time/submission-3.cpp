class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        dist[k]=0;
        for(int k = 1; k<=n-1; k++) {
            for(auto &e: times) {
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] != 1e9 && dist[u]+w < dist[v]) dist[v] = dist[u]+w;
            }
        }
        int res = *max_element(dist.begin()+1, dist.end());
        return (res==1e9)?-1:res;
    }
};
