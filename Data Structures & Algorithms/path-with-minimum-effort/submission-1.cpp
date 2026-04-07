class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int steps[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        int ROWS = heights.size(), COLS = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<int>> effort(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        q.push({0,0,0});
        effort[0][0] = 0;
        while(!q.empty()) {
            auto v = q.top(); q.pop();
            int cureffort = v[0], ci = v[1], cj = v[2];
            if(ci == ROWS-1 && cj == COLS-1) return cureffort;
            if (cureffort > effort[ci][cj]) continue;
            for(int i=0; i<4; i++) {
                int ni = ci+steps[i][0], nj = cj+steps[i][1];
                if(ni < 0 || nj < 0 || ni == ROWS || nj == COLS) continue;
                int neweffort = max(cureffort, abs(heights[ni][nj]-heights[ci][cj]));
                if(neweffort < effort[ni][nj]) {
                    effort[ni][nj] = neweffort;
                    q.push({neweffort, ni, nj});
                }
            }
        }
        return 0;
    }
};