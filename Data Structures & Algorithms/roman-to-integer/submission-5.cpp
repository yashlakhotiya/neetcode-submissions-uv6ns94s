class Solution {
public:
    unordered_map<char, int> romanmp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int num = 0;
        for(int i=0; i<s.size(); i++) {
            if(i+1 < s.size() && romanmp[s[i]] < romanmp[s[i+1]]) num -= romanmp[s[i]];
            else num += romanmp[s[i]];
        }
    return num;
    }
};