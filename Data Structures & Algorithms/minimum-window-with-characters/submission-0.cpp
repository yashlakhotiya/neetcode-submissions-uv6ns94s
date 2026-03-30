class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        string res="";
        int mchar=0;
        unordered_map<char, int> mps, mpt;
        for(char c: t) {
            mpt[c]++;
        }
        for(int r=0; r<s.size(); r++) {
            char c = s[r];
            mps[c]++;
            if(mpt.count(c) && mps[c] == mpt[c]) mchar++;
            while(mchar == mpt.size()) {
                if(res == "") res = s.substr(l, r-l+1);
                else if(r-l+1 < res.size()) res = s.substr(l, r-l+1);
                mps[s[l]]--;
                if(mpt.count(s[l]) && mps[s[l]] < mpt[s[l]]) mchar--;
                l++;
            }
        }
        return res;
    }
};

// OUZODYXAZV
// XYZ

// X:1 Y:1 Z:1
// mchar: 3
// O:0
// D:1
// U:0
// X:1
// Y:1
// Z:1 *

