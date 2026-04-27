class Solution {
public:
    bool ismatch(string &s, string &p, int sind, int pind) {
        if(sind >= s.size() && pind >= p.size()) return true;
        if(sind < s.size() && pind >= p.size()) return false;
        if(sind >= s.size()) {
            if(pind+1 < p.size() && p[pind+1] == '*') {
                return ismatch(s, p, sind, pind+2);
            } else return false;
        }
        if(pind+1 < p.size() && p[pind+1] == '*') {
            return ismatch(s, p, sind, pind+2) || ((p[pind] == '.' || s[sind]==p[pind]) && (ismatch(s, p, sind+1, pind) || ismatch(s, p, sind+1, pind+2)));
        } else {
            return (p[pind] == '.' || s[sind]==p[pind]) && ismatch(s, p, sind+1, pind+1);
        }
    }
    bool isMatch(string s, string p) {
        return ismatch(s, p, 0, 0);
    }
};


// xyzzz
// .*z

// x yzzz
// xy zzz (j>size but i <size) ret false
// xyz zz
// xyzz z
