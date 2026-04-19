class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int prod = 1;
            for(int j=i; j<nums.size(); j++) {
                prod *= nums[j];
                if(prod > res) {
                    res = prod;
                }
            }
        }
        return res;
    }
};
