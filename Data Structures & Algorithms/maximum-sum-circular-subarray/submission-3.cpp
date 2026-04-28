class Solution {
public:
    int kadanes(vector<int> &nums, bool findmax) {
        int cursummax = 0, cursummin = 0, maxi = -1e9, mini=1e9;
        for(int num: nums) {
            cursummax = max(num, cursummax+num);
            cursummin = min(num, cursummin+num);
            maxi = max(maxi, cursummax);
            mini = min(mini, cursummin);
        }
        return findmax?maxi:mini;
    } 
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        int maxsumnoncircular = kadanes(nums, true);
        int minsumnoncircular = kadanes(nums, false);
        int maxsumcircular = totalsum-minsumnoncircular;
        if(maxsumcircular == 0) return maxsumnoncircular;
        return max(maxsumnoncircular, maxsumcircular);
    }
};