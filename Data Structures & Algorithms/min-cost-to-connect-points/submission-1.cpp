class DS {
    vector<int> parent;
    vector<int> size;
    public:
    DS(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }

    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool unn(int i, int j) {
        int p1 = find(i), p2 = find(j);
        if(p1 == p2) return false;
        if(size[p1] > size[p2]) swap(p1, p2); // p2 is larger and hence parent of p1
        parent[p1] = p2;
        size[p2] += size[p1];
        return true;
    }
};

class Solution {
public:
    int getdist(int x1, int y1, int x2, int y2) {
        return abs(x1-x2)+abs(y1-y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DS ds(n);
        vector<vector<int>> edges;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = getdist(x1,y1,x2,y2);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        for(auto &e: edges) {
            int w=e[0], u=e[1], v=e[2];
            if(ds.unn(u,v)) res += w;
        }
        return res;
    }
};
