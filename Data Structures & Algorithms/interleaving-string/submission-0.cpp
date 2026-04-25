class Solution {
public:
    bool dfs(string&s1, string &s2, string &s, int i, int j, int k, bool comparefirst) {
        if(k == s.size()) return (i == s1.size()) && (j == s2.size());
        else {
            if((comparefirst && i == s1.size()) || (!comparefirst && j == s2.size())) return false;
        }
        if(comparefirst) {
            if(i < s1.size() && s1[i] != s[k]) return false;
            while(i < s1.size() && k < s.size() && s1[i] == s[k]) {
                i++; k++;
            }
            return dfs(s1, s2, s, i, j, k, !comparefirst);
        } else {
            if(j < s2.size() && s2[j] != s[k]) return false;
            while(j < s2.size() && k < s.size() && s2[j] == s[k]) {
                j++; k++;
            }
            return dfs(s1, s2, s, i, j, k, !comparefirst);
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(s1, s2, s3, 0, 0, 0, true) || dfs(s1, s2, s3, 0, 0, 0, false);
    }
};
