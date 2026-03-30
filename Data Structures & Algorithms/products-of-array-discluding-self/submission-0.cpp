class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> zeroPositions;
        int i=0;
        for(const int& num : nums) {
            if(num != 0) {
                product *= num;
                i++;
            }
            else zeroPositions.push_back(i++);
        }
        if(zeroPositions.size() > 1) return vector<int>(nums.size(), 0);
        else if(zeroPositions.size() == 1) {
            vector<int> res(nums.size(), 0);
            res[zeroPositions[0]] = product;
            return res;
        } else {
            vector<int> res(nums.size(), 0);
            int i=0;
            for(const int& num : nums) {
                res[i++] = int(product/num);
            }
            return res;
        }
    }
};
