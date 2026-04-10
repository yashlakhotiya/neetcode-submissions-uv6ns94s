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
        return parent[i]=find(parent[i]);
    }

    bool unn(int u, int v) {
        int p1=find(u), p2=find(v);
        if(p1==p2) return false;
        if(size[p1] < size[p2]) swap(p1,p2); // p1 is parent always
        parent[p2] = p1;
        size[p1] += size[p2];
        return true;
    }
};

class Kruskal {
    vector<vector<int>> edges;
    int n;
    public:
    vector<int> mst;
    int mstweight;
    Kruskal(int n, vector<vector<int>> &edges) {
        this->edges = edges;
        this->n = n;
        buildMst();
    }

    void buildMst() {
        DS ds(n);
        int mstwt = 0;
        for(int i=0; i<edges.size(); i++) {
            auto &edge = edges[i];
            int w = edge[0], u = edge[1], v = edge[2];
            if(ds.unn(u, v)) {
                mstwt += w;
                mst.push_back(i);
            }
        }
        mstweight = mstwt;
    }

    bool skipDoesntIncreasesMstWeight(int k) {
        DS ds(n);
        int mstwt = 0;
        int edgesused=0;
        for(int i=0; i<edges.size(); i++) {
            if(i == k) continue;
            auto &edge = edges[i];
            int w = edge[0], u = edge[1], v = edge[2];
            if(ds.unn(u, v)) {
                mstwt += w;
                edgesused++;
            }
        }
        if(edgesused == n-1 && mstwt == mstweight) return true;
        return false;
    }

    bool addDoesntChangeMstWeight(int k) {
        DS ds(n);
        ds.unn(edges[k][1], edges[k][2]);
        int mstwt = edges[k][0];
        int edgesused=1;
        for(int i=0; i<edges.size(); i++) {
            if(i == k) continue;
            auto &edge = edges[i];
            int w = edge[0], u = edge[1], v = edge[2];
            if(ds.unn(u, v)) {
                mstwt += w;
                edgesused++;
            }
        }
        if(edgesused == n-1 && mstwt == mstweight) return true;
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> newEdges;

for(int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int w = edges[i][2];
    newEdges.push_back({w, u, v, i});
}

sort(newEdges.begin(), newEdges.end());

Kruskal kruskal(n, newEdges);
        vector<vector<int>> res(2);
        for(int i=0; i<newEdges.size(); i++) {
            if(!kruskal.skipDoesntIncreasesMstWeight(i)) {
                res[0].push_back(newEdges[i][3]);
            } else if(kruskal.addDoesntChangeMstWeight(i)) {
                res[1].push_back(newEdges[i][3]);
            }
        }
        return res;
    }
};