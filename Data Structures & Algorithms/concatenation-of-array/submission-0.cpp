class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto ans = vector<int>(2*size(nums));
        int n = size(nums);
        for(int i=0; i<n; i++) {
            ans[i]=ans[i+n]=nums[i];
        }
        return ans;
    }
};