class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber <= 26) {
            int n = columnNumber-1;
            string res = "";
            res.push_back(char('A'+n));
            return res;
        }
        int n = columnNumber-1;
        return convertToTitle(n/26) + char('A'+n%26);
    }
};