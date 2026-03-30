class NumMatrix {
    vector<vector<int>> sumMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sumMatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(),0));
        int sum = 0;
        for(int i=0; i<matrix[0].size(); i++){
            sum += matrix[0][i];
            sumMatrix[0][i] = sum;
        }
        sum = 0;
        for(int i=0; i<matrix.size(); i++) {
            sum += matrix[i][0];
            sumMatrix[i][0] = sum;
        }
        for(int i=1; i<matrix.size(); i++) {
            for(int j=1; j<matrix[0].size(); j++) {
                sumMatrix[i][j] = matrix[i][j] + sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sumMatrix[row2][col2];
        if(row1-1 >= 0) res -= sumMatrix[row1-1][col2];
        if(col1-1 >= 0) res -= sumMatrix[row2][col1-1];
        if(row1-1 >= 0 && col1-1 >= 0) res += sumMatrix[row1-1][col1-1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//    0 1 2
// 0 |1,2,3|
// 1 |2,3,4|
// 2 |3,4,5|