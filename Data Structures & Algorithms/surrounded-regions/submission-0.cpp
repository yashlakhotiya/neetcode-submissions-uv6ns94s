class Solution {
    int ROWS, COLS;
    int steps[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size(), COLS = board[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if((i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) && board[i][j] == 'O') {
                    q.push({i,j});
                    board[i][j] = 'T';
                }
            }
        }
        while(!q.empty()) {
            auto [i,j] = q.front(); q.pop();
            for(int k=0; k<4; k++) {
                int ni = i+steps[k][0], nj = j+steps[k][1];
                if(ni < 0 || nj < 0 || ni >= ROWS || nj >= COLS) continue;
                if(board[ni][nj] == 'T') continue;
                if(board[ni][nj] == 'O') {
                    board[ni][nj] = 'T';
                    q.push({ni, nj});
                }
            }
        }
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
