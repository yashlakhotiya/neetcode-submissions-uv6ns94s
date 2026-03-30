class Solution {
public:
    vector<bool> cols;
    vector<bool> posdiag;
    vector<bool> negdiag;
    bool ispossibletoplace(vector<string> &board, int i, int j) {
        int n = board.size();
        if(!cols[j] && !posdiag[i+j] && !negdiag[i-j+n]) return true;
        return false;
    }
    void solve(vector<vector<string>> &res, vector<string> &board, int row) {
        int n = board.size();
        if(row == n) {
            res.push_back(board);
            return;
        }
        for(int j=0; j<board.size(); j++){
            if(ispossibletoplace(board, row, j)) {
                board[row][j] = 'Q';
                cols[j] = true;
                posdiag[row+j]=true;
                negdiag[row-j+n]=true;
                solve(res, board, row+1);
                board[row][j] = '.';
                cols[j] = false;
                posdiag[row+j]=false;
                negdiag[row-j+n]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        cols.resize(n);
        posdiag.resize(2*n);
        negdiag.resize(2*n);
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(res, board, 0);
        return res;
    }
};
