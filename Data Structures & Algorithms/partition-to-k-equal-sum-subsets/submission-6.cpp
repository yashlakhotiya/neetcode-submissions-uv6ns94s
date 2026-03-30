class Solution {
public:
    bool ispossible(vector<int> &nums, vector<bool> &visited, int target, int cursum, int k) {
        if(k == 0) return true;
        if(cursum == target) return ispossible(nums, visited, target, 0, k-1);
        for(int i=0; i<nums.size(); i++) {
            if(visited[i]) continue;
            if(cursum+nums[i] <= target) {
                visited[i] = true;
                if(ispossible(nums, visited, target, cursum+nums[i], k)) return true;
                visited[i] = false;
                if(cursum == 0) return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k != 0) return false;
        int target = sum/k;
        vector<bool> visited(nums.size(), false);
        int cursum = 0;
        return ispossible(nums, visited, target, cursum, k);
    }
};