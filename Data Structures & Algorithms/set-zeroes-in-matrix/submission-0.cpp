class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rowzero(matrix.size(), false);
        vector<bool> colzero(matrix[0].size(), false);
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    rowzero[i] = true;
                    colzero[j] = true;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(rowzero[i] || colzero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
