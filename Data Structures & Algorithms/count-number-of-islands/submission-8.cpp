class DS {
    vector<int> parent;
    vector<int> size;
    int components;
    public:
    DS(int n) : components(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n,1);
    }
    int findParent(int i) {
        if(i == parent[i]) return i;
        parent[i] = findParent(parent[i]);
        size[i] = 1;
        return parent[i];
    }

    bool unionsize(int i, int j) {
        int par1 = findParent(i), par2 = findParent(j);
        if(par1 == par2) return false;
        if(size[par1] >= size[par2]) {
            parent[par1] = par2;
            size[par2] += size[par1];
        } else {
            parent[par2] = par1;
            size[par1] += size[par2];
        }
        components--;
        return true;
    }

    int getNoofComponents() {
        return components;
    }
};

class Solution {
    int getidx(int i, int j) {
        return i*COLS+j;
    } 
public:
    int ROWS=0, COLS=0;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        DS ds = DS(grid.size()*grid[0].size());
        int res = 0;
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++) {
                int idx = getidx(i,j);
                if(grid[i][j] == '1') {
                    res++;
                    if(j+1 != COLS && grid[i][j+1] == '1' && ds.unionsize(idx, getidx(i, j+1))) res--;
                    if(j-1 != -1 && grid[i][j-1] == '1' && ds.unionsize(idx, getidx(i, j-1))) res--;
                    if(i+1 != ROWS && grid[i+1][j] == '1' && ds.unionsize(idx, getidx(i+1, j))) res--;
                    if(i-1 != -1 && grid[i-1][j] == '1' && ds.unionsize(idx, getidx(i-1, j))) res--;
                }
            }
        }
        return res;
    }
};
