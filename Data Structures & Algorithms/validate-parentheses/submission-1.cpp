class Solution {
public:
    bool isValid(string str) {
        stack<int> s;
        for(char c: str) {
            if(c == '{' || c == '(' || c == '[') {
                s.push(c);
            } else if (!s.empty() && ((c == '}' && s.top()=='{') || (c == ')' && s.top()=='(') || ( c == ']' && s.top() == '['))) {
                s.pop();
            } else return false;
        }
        if(s.empty()) return true;
        return false;
    }
};
