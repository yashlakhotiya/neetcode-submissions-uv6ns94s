class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastindex(26, 0);
        for(int i=0; i<s.size(); i++) {
            lastindex[s[i]-'a'] = i;
        }
        vector<int> res;
        int last = 0, currentlast = -1, l = 0;
        for(int i=0; i<s.size(); i++) {
            int last = lastindex[s[i]-'a'];
            currentlast = max(last, currentlast);
            if(i == currentlast) {
                res.push_back(i-l+1);
                l=i+1;
            }
        }
        return res;
    }
};
