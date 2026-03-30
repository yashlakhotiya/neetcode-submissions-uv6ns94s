class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s: strs) {
            res.append(to_string(s.size()));
            res.append("#");
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s == "") return {};
        int i = 0;
        vector<string> res;
        while(i < s.size()) {
            int sizeWord = getSizeOfWord(s, i);
            string word = getWord(s, i, sizeWord);
            res.push_back(word);
        }
        return res;
    }

    int getSizeOfWord(string s, int &i) {
        string sizeStr = "";
        while(i < s.size()) {
            if(s[i] == '#') {
                i++; break;
            }
            sizeStr += s[i++];
        }

        int size = stoi(sizeStr);
        return size;
    }

    string getWord(string s, int &i, int size) {
        string word = "";
        int length = 0;
        while(i < s.size() && length != size) {
            word += s[i++];
            length++;
        }
        return word;
    }

};