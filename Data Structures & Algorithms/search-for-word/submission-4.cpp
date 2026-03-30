class Solution {
public:
    vector<vector<int>> directions{{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool findword(vector<vector<char>>& board, string word, int i, int r, int c) {
        if(i == word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }
        char ch = board[r][c];
        board[r][c] = '#';
        for(auto d: directions) {
            int nr = r+d[0];
            int nc = c+d[1];
            if(findword(board, word, i+1, r+d[0], c+d[1])) return true;
        }
        board[r][c] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++){
                if(findword(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
