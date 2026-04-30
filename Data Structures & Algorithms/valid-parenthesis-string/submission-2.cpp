class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left;
        stack<int> star;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if(c == '(') left.push(i);
            else if(c == '*') star.push(i);
            else {
                if(!left.empty()) left.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!left.empty() && !star.empty()) {
            if(left.top() > star.top()) return false;
            left.pop(); star.pop();
        }
        return left.empty();
    }
};
