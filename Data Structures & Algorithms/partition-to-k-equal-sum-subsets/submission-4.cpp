class Solution {
public:
    bool checkequalsums(vector<int> &sums) {
        bool isequal = true;
        for(int i=1; i<sums.size(); i++) {
            isequal = isequal && (sums[i]==sums[i-1]);
            if(!isequal) return isequal;
        }
        return isequal;
    }
    bool ispossible(vector<int>& nums, int k, vector <int> &sums, int target) {
        if(k == nums.size()) {
            return true;
        }
        for(int i=0; i<sums.size(); i++) {
            if(i>0 && sums[i] == sums[i-1]) continue;
            if(sums[i]+nums[k] <= target) {
                sums[i] += nums[k];
                if(ispossible(nums, k+1, sums, target)) return true;
                sums[i] -= nums[k];
            }
            if(sums[i] == 0) return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0) return false;
        int target = sum/k;
        vector<int> sums(k, 0);
        sort(nums.rbegin(), nums.rend());
        return ispossible(nums, 0, sums, target);
    }
};