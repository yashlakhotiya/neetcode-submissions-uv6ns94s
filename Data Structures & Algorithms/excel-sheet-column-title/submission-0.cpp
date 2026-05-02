class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber <= 26) {
            int n = columnNumber-1;
            string res = "";
            res.push_back('A'+n);
            return res;
        }
        int n = columnNumber-1;
        return convertToTitle(columnNumber/26) + char('A'+n%26);
    }
};