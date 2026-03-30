class Solution {
public:
    bool ispalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void backtrack(string &s, int i, vector<vector<string>> &res, vector<string> &partitions) {
        if(i == s.size()) {
            res.push_back(partitions);
            return;
        }
        for(int j=i; j<s.size(); j++) {
            if(ispalindrome(s, i, j)) {
                partitions.push_back(s.substr(i, j-i+1));
                backtrack(s, j+1, res, partitions);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partitions;
        backtrack(s, 0, res, partitions);
        return res;
    }
};
