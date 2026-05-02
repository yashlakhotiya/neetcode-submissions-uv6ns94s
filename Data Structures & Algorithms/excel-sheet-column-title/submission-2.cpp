class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 26) {
            string res = "";
            res.push_back(char('A'+n-1));
            return res;
        }
        return convertToTitle(n/26) + char('A'+n%26-1);
    }
};