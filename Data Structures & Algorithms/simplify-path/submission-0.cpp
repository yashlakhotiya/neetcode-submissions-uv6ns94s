class Solution {
public:
    string simplifyPath(string path) {
        int k = 0;
        vector<string> s;
        while(k < path.size()) {
            char c = path[k];
            if(c == '/') k++;
            else {
                string token = "";
                while(k+1 < path.size() && path[k+1] != '/') {
                    token += path[k];
                    k++;
                }
                token += path[k++];
                if(token == ".") {}
                else if(token == "..") {
                    if(!s.empty()) s.pop_back();
                } else {
                    s.push_back(token);
                }
            }
        }
        string res = "/";
        for(string token: s) {
            res += token;
            res += "/";
        }
        if(res.size()>1) res.pop_back();
        return res;
    }
};