class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftUnknownPtr = 0, rightUnknownPtr = nums.size()-1;
        while(leftUnknownPtr <= rightUnknownPtr) {
            if(nums[leftUnknownPtr] != val) leftUnknownPtr++;
            else nums[leftUnknownPtr] = nums[rightUnknownPtr--];
        }
        return leftUnknownPtr;
    }
};

/* [1 1 2 3 4] val = 1

0 - left -> non val nos
left+1 -> right -> val nos

left = 0, right = size - 1;



*/

