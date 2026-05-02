class Solution {
public:
    bool isdivisor(string &s1, string &s2, int l) {
        if(s1.size()%l || s2.size()%l) return false;
        int f1 = s1.size()/l, f2 = s2.size()/l;
        string sf1 = "", sf2 = "";
        for(int i=1; i<=f1; i++) {
            sf1 += s1.substr(0,l);
        }
        for(int i=1; i<=f2; i++) {
            sf2 += s1.substr(0,l);
        }
        return s1 == sf1 && s2 == sf2;
    }
    string gcdOfStrings(string s1, string s2) {
        for(int l=min(s1.size(), s2.size()); l > 0; l--) {
            if(isdivisor(s1, s2, l)) return s1.substr(0, l);
        }
        return "";
    }
};