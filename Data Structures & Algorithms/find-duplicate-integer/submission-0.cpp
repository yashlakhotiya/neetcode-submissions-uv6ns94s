class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow) break;
        }
        int slown = 0;
        while(slown != slow) {
            slow = nums[slow];
            slown = nums[slown];
        }
        return slow;
    }
};
