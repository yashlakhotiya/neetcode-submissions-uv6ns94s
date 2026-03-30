class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        int i=0, j=0, p=0, q=0;
        while(l < r) {
            if(s[l] == s[r]) {
                l++; r--;
            } else {
                i=l+1; j=r;
                p=l; q=r-1;
                break;
            }
        }
        while(i < j) {
            if(s[i] == s[j]){
                i++; j--;
            } else {
                break;
            }
        }
        if(i >= j) return true;
        while(p < q) {
            if(s[p] == s[q]) {
                p++; q--;
            } else {
                return false;
            }
        }
        return true;
    }
};