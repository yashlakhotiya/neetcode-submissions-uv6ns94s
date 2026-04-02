class Solution {
    int steps[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    void dfs(vector<vector<char>>& board, int ci, int cj) {
        if(ci < 0 || cj < 0 || ci >= board.size() || cj >= board[0].size() || board[ci][cj] != 'O') return;
        board[ci][cj] = 'T';
        for(int i=0; i<4; i++) {
            int ni = ci + steps[i][0], nj = cj + steps[i][1];
            if(ni < 0 || nj < 0 || ni >= board.size() || nj >= board[0].size() || board[ni][nj] != 'O') continue;
            dfs(board, ni, nj);
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if((i==0 || i==board.size()-1 || j==0 || j == board[0].size()-1 ) && board[i][j] == 'O') dfs(board, i, j);
            }
        }
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'T') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};