class Solution {
    int d[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}};
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            auto [ci, cj] = q.front(); q.pop();
            if(ci < 0 || cj < 0 || ci == grid.size() || cj == grid[0].size() || grid[ci][cj] != '1') continue;
            grid[ci][cj] = '2';
            for(int k=0; k<4; k++) {
                int ni = ci+d[k][0], nj = cj+d[k][1];
                q.push({ni,nj});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
