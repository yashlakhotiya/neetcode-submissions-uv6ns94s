class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> input;
        for(int n : nums) {
            input.push_back(to_string(n));
        }
        auto cmp = [](string &a, string &b) {
            return a+b > b+a;
        };
        sort(input.begin(), input.end(), cmp);
        string res;
        for(string &str: input) {
            res += str;
        }
        return res[0]=='0'?"0":res;
    }
};