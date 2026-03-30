class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char,int> mp1, mp2;
        for(char c: s1) mp1[c]++;
        int l=0, numcharMatched=0;
        for(int r=0; r<s2.size(); r++) {
            mp2[s2[r]]++;
            if(mp1.find(s2[r]) != mp1.end() && mp1[s2[r]] == mp2[s2[r]]) numcharMatched++;
            if(r-l+1 > s1.size()){
                if(mp1.find(s2[l]) != mp1.end() && mp1[s2[l]] == mp2[s2[l]]) numcharMatched--;
                mp2[s2[l]]--;
                if(!mp2[s2[l]]) mp2.erase(s2[l]);
                l++;
            }
            if(r-l+1 == s1.size()) {
                if(numcharMatched == mp1.size()) return true;
            }
        }
        return false;
    }
};
