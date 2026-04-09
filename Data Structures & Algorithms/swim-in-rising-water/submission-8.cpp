class Solution {
public:
    int x[4] = {0,1,0,-1};
    int y[4] = {-1,0,1,0};
    int swimInWater(vector<vector<int>>& grid) {
        int ROWS=grid.size(), COLS=grid[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> pq;
        auto getid = [&](int i, int j) {
            return i*COLS+j;
        };
        pq.push({grid[0][0],0});
        vector<bool> visited(ROWS*COLS, false);
        int targetid = getid(ROWS-1, COLS-1);
        while(!pq.empty()) {
            auto [t, id] = pq.top(); pq.pop();
            if(visited[id]) continue;
            if(id == targetid) return t;
            
            visited[id] = true;
            for(int i=0; i<4; i++) {
                int ci=id/COLS, cj=id%COLS;
                int ni=ci+x[i], nj=cj+y[i];
                if(ni<0||nj<0||ni>=ROWS||nj>=COLS||visited[getid(ni, nj)]) continue;
                pq.push({max(t, grid[ni][nj]), getid(ni, nj)});
            }
        }
        return -1;
    }
};
