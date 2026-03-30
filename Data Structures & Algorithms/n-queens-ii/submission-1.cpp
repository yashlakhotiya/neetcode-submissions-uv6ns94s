class Solution {
public:
    vector<int> cols;
    vector<int> posdiag;
    vector<int> negdiag;
    bool issafe(int n, int i, int j) {
        return !cols[j] && !posdiag[i+j] && !negdiag[i-j+n];
    }

    int solve(int n, int row) {
        int count = 0;
        if(row == n) return 1;
        for(int j=0; j<n; j++) {
            if(!issafe(n, row, j)) continue;
            cols[j] = true;
            posdiag[row+j] = true;
            negdiag[row-j+n] = true;
            count += solve(n, row+1);
            cols[j] = false;
            posdiag[row+j] = false;
            negdiag[row-j+n] = false;
        }
        return count;
    }

    int totalNQueens(int n) {
        cols.assign(n,false);
        posdiag.assign(2*n, false);
        negdiag.assign(2*n, false);
        return solve(n, 0);
    }
};