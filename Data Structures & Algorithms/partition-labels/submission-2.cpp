class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastindex(26, 0);
        for(int i=0; i<s.size(); i++) {
            lastindex[s[i]-'a'] = i;
        }
        vector<int> res;
        int currentwindowlastidx = -1, l = 0;
        for(int r=0; r<s.size(); r++) {
            currentwindowlastidx = max(lastindex[s[r]-'a'], currentwindowlastidx);
            if(r == currentwindowlastidx) {
                res.push_back(r-l+1);
                l=r+1;
            }
        }
        return res;
    }
};
