class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> directories;
        string directoryname;
        while(getline(ss, directoryname, '/')) {
            if(directoryname == "..") {
                if(!directories.empty()) directories.pop_back();
            } else if(directoryname == "." || directoryname == "") {
                continue;
            } else {
                directories.push_back(directoryname);
            }
        }
        if(directories.empty()) return "/";
        string res = "";
        for(string &dir: directories) {
            res += "/"+dir;
        }
        return res;
    }
};