class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSumFreqMap;
        prefixSumFreqMap[0] = 1;
        int res = 0;
        int sum = 0; 
        for(int num : nums) {
            sum += num;
            int requiredPrefixSum = sum-k;
            res+= prefixSumFreqMap[requiredPrefixSum];
            prefixSumFreqMap[sum]++;
        }
        return res;
    }
};
