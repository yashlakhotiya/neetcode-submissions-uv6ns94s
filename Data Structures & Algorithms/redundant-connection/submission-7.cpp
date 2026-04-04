class DS {
    vector<int> rank;
    vector<int> parent;
    int nocomp;
    public: 
    DS(int n) : nocomp(n) {
        rank.assign(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool unon(int i, int j) {
        int p1 = find(i), p2 = find(j);
        if(p1 == p2) return false;
        if(rank[p2] > rank[p1]) {
            swap(p1, p2);
        }
        parent[p2] = p1;
        if(rank[p1] == rank[p2]) rank[p1]++;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DS ds(n+1);
        vector<int> res;
        for(auto &e: edges) {
            if(!ds.unon(e[0], e[1])) res=e;
        }
        return res;
    }
};
