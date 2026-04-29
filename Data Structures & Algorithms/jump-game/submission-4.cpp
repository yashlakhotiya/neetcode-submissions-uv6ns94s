class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetidx = nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--) {
            if(i+nums[i] >= targetidx) targetidx = i;
        }
        return targetidx==0;
    }
};
