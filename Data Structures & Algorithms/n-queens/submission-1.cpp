class Solution {
public:
    bool ispossibletoplace(vector<string> &board, int i, int j) {
        int n = board.size();
        for(int k=0; k<board.size(); k++) {
            //check same row
            if(board[i][k] == 'Q') return false;
            // check same col
            if(board[k][j] == 'Q') return false;
        }
        //check diagonal top right
        for(int k=i,l=j; k<n && l<n && k>=0 && l>=0; k--,l++) {
            if(board[k][l] == 'Q') return false;
        }
        // check diagonal top left
        for(int k=i,l=j; k<n && l<n && k>=0 && l>=0; k--,l--) {
            if(board[k][l] == 'Q') return false;
        }
        // check diagonal bottom right
        for(int k=i,l=j; k<n && l<n && k>=0 && l>=0; k++,l++) {
            if(board[k][l] == 'Q') return false;
        }
        //check diagonal bottom left
        for(int k=i,l=j; k<n && l<n && k>=0 && l>=0; k++,l--) {
            if(board[k][l] == 'Q') return false;
        }
        return true;
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
                solve(res, board, row+1);
                board[row][j] = '.';
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
