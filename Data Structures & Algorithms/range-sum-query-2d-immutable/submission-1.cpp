class NumMatrix {
public:
    vector<vector<int>> sumFromOrigin;
    NumMatrix(vector<vector<int>>& matrix) {
        sumFromOrigin.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        sumFromOrigin[0][0] = matrix[0][0];
        for(int i=1; i<matrix.size(); i++) {
            sumFromOrigin[i][0] = sumFromOrigin[i-1][0]+matrix[i][0];
        }
        for(int i=1; i<matrix[0].size(); i++) {
            sumFromOrigin[0][i] = sumFromOrigin[0][i-1]+matrix[0][i];
        }
        for(int i=1; i<matrix.size(); i++) {
            for(int j=1; j<matrix[0].size(); j++) {
                sumFromOrigin[i][j] = sumFromOrigin[i-1][j]+sumFromOrigin[i][j-1]-sumFromOrigin[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = sumFromOrigin[row2][col2];
        if(row1 > 0) {
            sum -= sumFromOrigin[row1-1][col2];
        }
        if(col1 > 0) {
            sum -= sumFromOrigin[row2][col1-1];
        }
        if(row1 > 0 && col1 > 0) {
            sum += sumFromOrigin[row1-1][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */