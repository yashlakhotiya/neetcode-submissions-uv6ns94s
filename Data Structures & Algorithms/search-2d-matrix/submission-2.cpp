class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS=matrix.size(), COLS=matrix[0].size();
        int l=0, r=ROWS*COLS-1, m;
        while(l <= r) {
            m = l+(r-l)/2;
            int x = m/COLS, y = m%COLS;
            if(target == matrix[x][y]) return true;
            else if(target < matrix[x][y]) r = m-1;
            else l = m+1;
        }
        return false;
    }
};
