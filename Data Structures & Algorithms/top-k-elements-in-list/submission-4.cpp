class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqmp;
        for(int num: nums) freqmp[num]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto &[num, freq]: freqmp) {
            bucket[freq].push_back(num);
        }
        vector<int> res;
        int ressize = k;
        for(int i=nums.size(); i>=0; i--) {
            if(k == 0) break;
            auto freqnums = bucket[i];
            int size = freqnums.size();
            while(!freqnums.empty() && k--) {
                res.push_back(freqnums.back());
                freqnums.pop_back();
            }
        }
        return res;
    }
};
