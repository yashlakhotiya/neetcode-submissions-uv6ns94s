class Solution {
public:
    bool isMatch(string s, string p) {
        vector<int> curr(p.size()+1, 0);
        int nxtnxt = 0, nxtcur = 0;
        for(int sind=s.size(); sind>=0; sind--) {
            for(int pind=p.size(); pind>=0; pind--) {
                bool res = false;
                nxtcur = curr[pind];
                if(pind >= p.size()) {
                    res = (sind >= s.size());
                } else {
                    if(pind+1 < p.size() && p[pind+1] == '*') {
                        if(sind >= s.size()) res = curr[pind+2];
                        else res = curr[pind+2] || 
                        ((p[pind] == '.' || s[sind]==p[pind]) && nxtcur);
                    } else {
                        if(sind >= s.size()) res = false;
                        else res = (p[pind] == '.' || s[sind]==p[pind]) && nxtnxt;
                    }
                }
                nxtnxt = nxtcur;
                curr[pind] = res;
            }
        }
        return curr[0];
    }
};

// curr[pind+2]
// next[pind]
// next[pind+1]