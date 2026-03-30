class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()-1, m=0;
        bool exists = false;
        int row = -1;
        while(l <= r) {
            m = l+(r-l)/2;
            if(target >= matrix[m][0] && target <= matrix[m][matrix[0].size()-1]) {
                row=m;
                break;
            } else if (target < matrix[m][0]) {
                r = m-1;
            } else l = m+1;
        }
        if(row == -1) return false;
        l = 0, r = matrix[0].size()-1, m=0;
        while(l <= r) {
            m = l+(r-l)/2;
            if(target == matrix[row][m]) return true;
            else if(target < matrix[row][m]) r=m-1;
            else l=m+1;
        }
        return false;
    }
};
