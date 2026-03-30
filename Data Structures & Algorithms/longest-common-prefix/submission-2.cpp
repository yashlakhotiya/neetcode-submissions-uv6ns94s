class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i=0; i<200; i++) {
            char tempChar = '\0';
            for(const string &s: strs) {
                if(s.size() == 0) {
                    return "";
                }
                if(s.size()-1 < i) {
                    return prefix;
                }
                if(tempChar == '\0') {
                    tempChar = s[i];
                } else {
                    if(s[i] != tempChar) return prefix;
                }
            }
            prefix += tempChar;
        }
        return prefix;
    }
};