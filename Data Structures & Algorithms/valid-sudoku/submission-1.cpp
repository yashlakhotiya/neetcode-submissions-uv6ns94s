class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> res;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                if(res.find(board[i][j]) != res.end()) return false;
                res.insert(board[i][j]);
            }
            res.clear();
        }
        res.clear();
        for(int j=0; j<board[0].size(); j++) {
            for(int i=0; i<board.size(); i++) {
                if(board[i][j] == '.') continue;
                if(res.find(board[i][j]) != res.end()) return false;
                res.insert(board[i][j]);
            }
            res.clear();
        }
        res.clear();

        for(int k=0; k<9; k+=3) {
            for(int l=0; l<9; l+=3) {
                for(int i=k; i<k+3; i++) {
                    for(int j=l; j<l+3; j++) {
                        if(board[i][j] == '.') continue;
                        if(res.find(board[i][j]) != res.end()) return false;
                        res.insert(board[i][j]);
                    }
                }
                res.clear();
            }
        }

        return true;
    }
};
