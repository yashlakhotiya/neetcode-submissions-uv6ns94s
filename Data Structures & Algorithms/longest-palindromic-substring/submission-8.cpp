class Solution {
public:
    bool ispalindrome(string &s, int l, int r) {
        if(l >= r) return true;
        return s[l] == s[r] && ispalindrome(s, l+1, r-1);
    }
    string longestPalindrome(string s) {
        string res = "";
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(ispalindrome(s, i, j) && j-i+1 > res.size()) {
                    res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};
