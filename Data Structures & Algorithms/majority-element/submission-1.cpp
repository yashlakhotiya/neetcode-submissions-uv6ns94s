class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = -1, majCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(majCount == 0) {
                maj = nums[i];
                majCount++;
                continue;
            }
            if(nums[i] == maj) majCount++;
            else majCount--;
        }
        return maj;        
    }
};