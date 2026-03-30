class FreqStack {
    unordered_map<int,int> freqmp;
    unordered_map<int, stack<int>> catmap;
    int maxcnt;
public:
    FreqStack() {
        maxcnt=0;
    }
    
    void push(int val) {
        freqmp[val]++;
        if(freqmp[val] > maxcnt) {
            maxcnt = freqmp[val];
        }
        catmap[freqmp[val]].push(val);
    }
    
    int pop() {
        int res = catmap[maxcnt].top(); catmap[maxcnt].pop();
        freqmp[res]--;
        if(catmap[maxcnt].empty()) maxcnt--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */