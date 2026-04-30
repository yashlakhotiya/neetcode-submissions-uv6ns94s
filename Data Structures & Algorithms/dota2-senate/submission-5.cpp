class Solution {
public:
    string getSenateName(string &senate, int i) {
        return senate[i]=='R'?"Radiant":"Dire";
    }
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;
        int n = senate.size();
        for(int i=0; i<n; i++){
            senate[i]=='R'?rq.push(i):dq.push(i);
        }
        while(!rq.empty() && !dq.empty()) {
            int rfront = rq.front(); rq.pop();
            int dfront = dq.front(); dq.pop();
            if(rfront < dfront) {
                rq.push(rfront+n);
            } else {
                dq.push(dfront+n);
            }
        }
        if(rq.empty()) return "Dire";
        else return "Radiant";
    }
};