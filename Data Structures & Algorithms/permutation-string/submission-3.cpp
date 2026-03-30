class Solution {
public:
    bool equalMaps(unordered_map<char,int> &m1, unordered_map<char,int> &m2) {
        if(m1.size()!= m2.size()) return false;
        for(auto &[k,v] : m1) {
            if(m2.find(k) == m2.end()) return false;
            if(m2[k] != v) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char,int> mp1, mp2;
        for(char c: s1) mp1[c]++;
        int l=0, r=0, wsize=0;
        while(true) {
            if(r < s2.size() && wsize < s1.size()) {
                mp2[s2[r++]]++;
                wsize++;
            } else {
                if(equalMaps(mp1, mp2)) return true;
                else if(r >= s2.size()) return false;
                else {
                    mp2[s2[l]]--;
                    if(!mp2[s2[l]]) mp2.erase(s2[l]);
                    l++;
                    wsize--;
                }
            }
        }
        return false;
    }
};
