class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return 0;
        unordered_map<char,int> mp;
        for(char c: s) {
            mp[c]++;
        }
        for(char c: t) {
            if(mp.find(c) == mp.end()) return false;
            if(mp[c] == 0) return false;
            mp[c]--;
            if(mp[c] == 0) mp.erase(c);
        }
        if(mp.size() == 0) return true;
        return false;
    }
};
