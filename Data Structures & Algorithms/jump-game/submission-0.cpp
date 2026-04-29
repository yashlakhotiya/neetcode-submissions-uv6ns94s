class Solution {
public:
    bool canjump(vector<int> &nums, int i) {
        if(i == nums.size()-1) return true;
        int jump = nums[i];
        for(int k=1; k<=jump; k++) {
            int jumpidx = i+k;
            if(jumpidx < nums.size()) {
                if(canjump(nums, jumpidx)) return true;
            }
        }   
        return false;
    }
    bool canJump(vector<int>& nums) {
        return canjump(nums, 0);
    }
};
