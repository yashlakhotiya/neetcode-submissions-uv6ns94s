class DS {
    vector<int> parent;
    vector<int> size;
    int nocomponents;
    public: 
    DS(int n) : nocomponents(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n,1);
    }

    int find(int i) {
        if(i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    bool unon(int i, int j) {
        int p1 = find(i), p2 = find(j);
        if(p1 == p2) return false;
        if(size[p1] > size[p2]) swap(p1, p2);
        parent[p1] = p2;
        size[p2] += size[p1];
        nocomponents--;
        return true;
    }
    
    int getcomp() {
        return nocomponents;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DS ds(n);
        for(auto &e: edges) {
            ds.unon(e[0], e[1]);
        }
        return ds.getcomp();
    }
};
