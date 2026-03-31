class DS {
    vector<int> p;
    vector<int> s;
    int components;
    public:
    DS(int n) : components(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        s.assign(n, 1);
    }

    int find(int idx) {
        if(idx == p[idx]) return idx;
        return p[idx] = find(p[idx]);
    }

    bool unionall(int idx1, int idx2) {
        int p1 = find(idx1), p2 = find(idx2);
        if(p1 == p2) return false;
        if(s[p1] <= s[p2]) {
            p[p1] = p2;
            s[p2] += s[p1];
        } else {
            p[p2] = p1;
            s[p1] += s[p2];
        }
        return true;
    }

    int getsize(int idx) {
        return s[find(idx)];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS=grid.size(), COLS=grid[0].size();
        DS ds = DS(ROWS*COLS);
        auto getid = [&](int i, int j) {
            return i*COLS+j;
        };
        int maxi = 0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(grid[i][j] == 1) {
                    if(j+1 < COLS && grid[i][j+1] == 1) ds.unionall(getid(i,j), getid(i, j+1));
                    if(i+1 < ROWS && grid[i+1][j] == 1) ds.unionall(getid(i,j), getid(i+1, j));
                    maxi = max(maxi, ds.getsize(getid(i,j)));
                }
            }
        }
        return maxi;
    }
};
