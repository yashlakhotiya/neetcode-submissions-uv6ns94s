class Solution {   
    int steps[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}}; 
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int dist) {
        if(dist > grid[i][j]) return;
        grid[i][j] = min(grid[i][j], dist);
        for(int k=0; k<4; k++) {
            int ni = i+steps[k][0], nj = j+steps[k][1];
            if(ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size()) continue;
            if(grid[ni][nj] == 0 || grid[ni][nj] == -1) continue;
            dfs(grid, ni, nj, dist+1);
        }
    }

    void bfs(vector<vector<int>>& grid) {
        int ROWS=grid.size(), COLS=grid[0].size();
        queue<int> q;
        auto getidx = [&](int i, int j) {
            return i*COLS+j;
        };
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(grid[i][j] == 0) {
                    q.push(getidx(i,j));
                }
            }
        }
        while(!q.empty()) {
            int ind = q.front();
            int i = ind/COLS, j = ind%COLS; q.pop();
            int dist = grid[i][j];
            for(auto &v: steps) {
                int ni = i+v[0], nj = j+v[1];
                if(ni < 0 || nj < 0 || ni >= ROWS || nj >= COLS) continue;
                if(grid[ni][nj] == 2147483647) {
                    grid[ni][nj] = dist+1;
                    q.push(getidx(ni,nj));
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);
        // for(int i=0; i<grid.size(); i++) {
        //     for(int j=0; j<grid[0].size(); j++) {
        //         if(grid[i][j] == 0) {
        //             dfs(grid, i, j, 0);
        //         }
        //     }
        // }
    }
};
