class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> rowmp, colmp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        rowmp[point[0]][point[1]]++;
        colmp[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int row = point[0], col = point[1];
        int res = 0;
        for(auto &[colpt, freq]: rowmp[row]) {
            if(colpt == col) continue;
            int length = abs(col-colpt);
            if(colmp[colpt].count(row+length) && colmp[col].count(row+length)) {
                res += (freq*colmp[colpt][row+length]*colmp[col][row+length]);
            }
            if(colmp[colpt].count(row-length) && colmp[col].count(row-length)) {
                res += (freq*colmp[colpt][row-length]*colmp[col][row-length]);
            }
        }
        return res;
    }
};
