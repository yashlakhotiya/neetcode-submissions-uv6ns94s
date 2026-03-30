class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l=0;
        int maxf = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++) {
            mp[s[r]]++; maxf = max(maxf, mp[s[r]]);
            while((r-l+1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
