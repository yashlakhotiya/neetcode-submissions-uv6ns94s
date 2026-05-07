class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr(n+1, -1);
        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i == m-1 && j == n-1) curr[j] = 1;
                else if(i == m || j == n) curr[j] = 0;
                else {
                    int next = curr[j];
                    curr[j]= next + curr[j+1];
                }
            }
        }
        return curr[0];
    }
};
