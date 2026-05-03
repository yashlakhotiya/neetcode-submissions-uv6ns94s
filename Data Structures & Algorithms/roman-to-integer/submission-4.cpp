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
        int i=0;
        char prev=0;
        int num = 0, temp = 0;
        while(i < s.size()) {
            char curr = s[i];
            if(prev == 0) {
                prev = curr;
                temp = romanmp[curr];
                i++;
            } else if(romanmp[curr] == romanmp[prev]) {
                num += temp;
                temp = romanmp[curr];
                i++;
            } else if(romanmp[curr] > romanmp[prev]) {
                num += romanmp[curr]-temp;
                temp = 0;
                prev = 0;
                i++;
            } else if(romanmp[curr] < romanmp[prev]) {
                num += temp; temp = romanmp[curr]; prev = curr;
                i++;
            }
        }
        if(temp) num += temp;
        return num;
    }
};