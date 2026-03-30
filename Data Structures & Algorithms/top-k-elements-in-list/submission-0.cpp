class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> numFreq;
        for(int n : nums) {
            numFreq[n]++;
        }
        map<int,vector<int>> freqNo;
        for(auto it = numFreq.begin(); it != numFreq.end(); it++){
            freqNo[-1*it->second].push_back(it->first);
        }
        vector<int> res;
        for(auto it = freqNo.begin(); it != freqNo.end(); it++) {
            vector<int> nos = it->second;
            int requiredNoOfElements = k-res.size();
            if(requiredNoOfElements == 0) return res;
            if(nos.size() <= requiredNoOfElements) {
                for(auto n : nos) res.push_back(n);
            } else {
                for(int i=0; i<requiredNoOfElements; i++) {
                    res.push_back(nos[i]);
                }
            }
        }
        return res;
    }
};
