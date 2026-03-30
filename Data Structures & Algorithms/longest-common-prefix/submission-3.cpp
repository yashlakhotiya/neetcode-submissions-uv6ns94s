class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs[0].size() == 0) return prefix;
        for(int i=0; i<strs[0].size(); i++) {
            for(const string &s: strs) {
                if(i+1 > s.size()) return prefix;
                if(s[i] != strs[0][i]) return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};