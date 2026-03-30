class Solution {
public:
    void backtrack(int n, vector<string> &res, string temp, int open, int close) {
        if(temp.size() == 2*n && open == close) {
            res.push_back(temp);
            return;
        }
        if(open == close && open < n) {
            backtrack(n, res, temp + "(", open+1, close);
        } else if(open > close) {
            if(open < n) {
                backtrack(n, res, temp + "(", open+1, close);
            }
            backtrack(n, res,  temp + ")", open, close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, res, "", 0, 0);
        return res;
    }
};







