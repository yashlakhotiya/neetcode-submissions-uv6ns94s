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



        for(int i=nums.size(); i>=0; i--) {
            auto freqnums = bucket[i];
            if(freqnums.size() == 0) continue;
            int size = freqnums.size();
            while(!freqnums.empty() && res.size() < k) {
                res.push_back(freqnums.back());
                freqnums.pop_back();
            }
            if(res.size() == k) return res;
        }
        return res;
    }
};
