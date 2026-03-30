class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int steps = k%nums.size();
        if(steps==0) return;
        vector<int> temp(k, 0);
        for(int i=0; i<steps; i++) {
            temp[i] = nums[nums.size()-steps+i];
        }
        int i=nums.size()-steps-1, j=nums.size()-1;
        while(i>=0) {
            nums[j--] = nums[i--];
        }
        for(int i=0; i<steps; i++) {
            nums[i] = temp[i];
        }
        return;
    }
};