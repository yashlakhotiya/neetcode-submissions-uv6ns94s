class Solution {
public:
    set<int> cols;
    set<int> posdiag;
    set<int> negdiag;
    bool ispossibletoplace(vector<string> &board, int i, int j) {
        int n = board.size();
        if(!cols.count(j) && !posdiag.count(i+j) && !negdiag.count(i-j)) return true;
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
                cols.insert(j);
                posdiag.insert(row+j);
                negdiag.insert(row-j);
                solve(res, board, row+1);
                board[row][j] = '.';
                cols.erase(j);
                posdiag.erase(row+j);
                negdiag.erase(row-j);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(res, board, 0);
        return res;
    }
};
