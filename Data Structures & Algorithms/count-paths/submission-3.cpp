class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr(n+1, -1), next(n+1, 0);
        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i == m-1 && j == n-1) curr[j] = 1;
                else if(i == m || j == n) curr[j] = 0;
                else {
                    curr[j]=next[j] + curr[j+1];
                }
            }
            next = curr;
        }
        return next[0];
    }
};
