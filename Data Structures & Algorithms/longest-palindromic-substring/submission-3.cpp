class Solution {
public:
    bool ispalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        string res = "";
        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(ispalindrome(s, i, j)) {
                    if(j-i+1 > res.size()) res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};
