class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rowSeen(board.size());
        vector<set<char>> colSeen(board[0].size());
        vector<vector<set<char>>> gridSeen(3, vector<set<char>>(3));

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                if(rowSeen[i].count(board[i][j]) ||
                colSeen[j].count(board[i][j]) || 
                gridSeen[i/3][j/3].count(board[i][j])) return false;
                rowSeen[i].insert(board[i][j]);
                colSeen[j].insert(board[i][j]);
                gridSeen[i/3][j/3].insert(board[i][j]);
            }
        }

        return true;
    }
};
