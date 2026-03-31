class Solution {
public:
    int ROWS, COLS;
    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<int> q;
        q.push(r*COLS+c);
        int res = 0;
        while(!q.empty()) {
            int top = q.front(); q.pop();
            int i = top/COLS, j = top%COLS;
            if(i < 0 || j < 0 || i >= ROWS || j >= COLS || grid[i][j] != 1) continue;
            grid[i][j] = 2;
            res++;
            if(j+1 < COLS) q.push(i*COLS + (j+1));
            if(j-1 >= 0) q.push(i*COLS + (j-1));
            if(i+1 < ROWS) q.push((i+1)*COLS + j);
            if(i-1 < ROWS) q.push((i-1)*COLS + j);
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size(), COLS=grid[0].size();
        int maxi=0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(grid[i][j] == 1) {
                    maxi = max(maxi, bfs(grid, i, j));
                }
            }
        }
        return maxi;
    }
};
