class Solution {
public:
    bool equalMap(unordered_map<int,int> m1, unordered_map<int,int> m2) {
        if(m1.size()!=m2.size()) return false;
        for(auto i : m1) {
            if(!m2[i.first]) return false;
            if(m1[i.first] != m2[i.first]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<int,int> s1mp;
        for(int i=0; i<s1.size(); i++) s1mp[s1[i]]++;
        for(int i=0; i<=s2.size()-s1.size(); i++) {
            unordered_map<int,int> s2mp;
            for(int j=i; j<i+s1.size(); j++) {
                s2mp[s2[j]]++;
            }
            if(equalMap(s1mp, s2mp)) return true;
            s2mp.clear();
        }
        return false;
    }
};

// aabbcc

// aabbcqaabbcc