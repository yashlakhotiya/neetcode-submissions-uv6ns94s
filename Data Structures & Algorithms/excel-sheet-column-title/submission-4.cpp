class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string res = "";
        while(n > 0) {
            n--;
            int rem = n%26;
            n /= 26;
            res.push_back(char('A'+rem));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};