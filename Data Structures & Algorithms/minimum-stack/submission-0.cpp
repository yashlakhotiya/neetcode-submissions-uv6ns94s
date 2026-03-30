class MinStack {
public:
    stack<int> s1, s2;
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()) s2.push(x);
        else {
            s2.push(x<=s2.top()?x:s2.top());
        }
    }
    
    void pop() {
        s1.pop(); s2.pop(); 
    }
    
    int top() {
        int x = s1.top();
        return x;
    }
    
    int getMin() {
        return s2.top();
    }
};
