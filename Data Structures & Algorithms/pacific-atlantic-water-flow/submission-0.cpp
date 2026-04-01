class Solution {
    int steps[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS=heights.size(), COLS=heights[0].size();
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        queue<pair<int,int>> pacificq, atlanticq;
        for(int j=0; j<COLS; j++) {
            pacificq.push({0,j});
            pacific[0][j] = true;
            atlanticq.push({ROWS-1, j});
            atlantic[ROWS-1][j] = true;
        }
        for(int i=0; i<ROWS; i++) {
            pacificq.push({i,0});
            pacific[i][0] = true;
            atlanticq.push({i, COLS-1});
            atlantic[i][COLS-1] = true;
        }
        while(!pacificq.empty()) {
            auto [ci, cj] = pacificq.front();
            pacificq.pop();
            for(int i=0; i<4; i++) {
                int ni = ci + steps[i][0], nj = cj + steps[i][1];
                if(ni < 0 || nj < 0 || ni >= ROWS || nj >= COLS || pacific[ni][nj] || heights[ni][nj] < heights[ci][cj]) continue;
                pacific[ni][nj] = true;
                pacificq.push({ni,nj});
            }
        }
        while(!atlanticq.empty()) {
            auto [ci, cj] = atlanticq.front();
            atlanticq.pop();
            for(int i=0; i<4; i++) {
                int ni = ci + steps[i][0], nj = cj + steps[i][1];
                if(ni < 0 || nj < 0 || ni >= ROWS || nj >= COLS || atlantic[ni][nj] || heights[ni][nj] < heights[ci][cj]) continue;
                atlantic[ni][nj] = true;
                atlanticq.push({ni,nj});
            }
        }
        vector<vector<int>> res;
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++) {
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
