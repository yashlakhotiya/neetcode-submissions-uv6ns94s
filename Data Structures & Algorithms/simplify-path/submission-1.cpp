class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        stringstream ss(path);
        string cur;
        while(getline(ss, cur, '/')) {
            if(cur.empty()) continue;
            else if(cur == "..") {
                if(!s.empty()) s.pop_back();
            } else if(!cur.empty() && cur != ".") {
                s.push_back(cur);
            }
        }
        string res = "";
        for(int i=0; i<s.size(); i++) {
            res += "/";
            res += s[i];
        }
        return res.empty()?"/":res;
    }
};