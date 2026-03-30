class Solution {
public:
    int subsetxorsum(vector<int> &arr, int i, int total) {
        if(i == arr.size()) return total;
        return subsetxorsum(arr, i+1, arr[i]^ total) +
                subsetxorsum(arr, i+1, total);
    }
    int subsetXORSum(vector<int>& nums) {
        return subsetxorsum(nums, 0, 0);
    }
};