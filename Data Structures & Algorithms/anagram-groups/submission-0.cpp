class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(const string &s : strs) {
            mp[getAnagramSignature(s)].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it = mp.begin(); it != mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }

    string getAnagramSignature(string word) {
        map<char,int> mp;
        for(char c: word){
            mp[c]++;
        }
        string res = "";
        for(auto it = mp.begin(); it != mp.end(); it++){
            res += it->first;
            res += to_string(it->second);
        }
        return res;
    }
};
