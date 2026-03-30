class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l=0, r=0;
        int maxf = 0;
        int res = 0;
        mp[s[r]]++;
        maxf=max(maxf, mp[s[r]]);
        while(r < s.size()) {
            int noOfCharsInWindow = r-l+1;
            if(noOfCharsInWindow-maxf <= k) {
                res = max(res, r-l+1);
                r++;
                mp[s[r]]++;
                maxf=max(maxf, mp[s[r]]);
            } else {
                mp[s[l]]--;;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};
