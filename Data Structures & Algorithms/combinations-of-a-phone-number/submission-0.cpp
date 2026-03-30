class Solution {
public:
    void backtrack(string &digits, int k, string &temp, vector<string> &res, unordered_map<char,vector<char>> &mp){
        if(k == digits.size()) {
            res.push_back(temp);
            return;
        }
        for(int i=0; i<mp[digits[k]].size(); i++) {
            temp += mp[digits[k]][i];
            backtrack(digits, k+1, temp, res, mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char,vector<char>> mp;
        vector<string> res;
        char st = 'a';
        for(char ch='2'; ch<='9'; ch++) {
            mp[ch].push_back(st++);
            mp[ch].push_back(st++);
            mp[ch].push_back(st++);
            if(ch == '7' || ch == '9') {
                mp[ch].push_back(st++);
            }
            if(st == 'Z') break;
        }
        string temp = "";
        backtrack(digits, 0, temp, res, mp);
        return res;
    }
};
