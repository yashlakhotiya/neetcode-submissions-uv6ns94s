class Solution {
public:
    int findnextoppavailablesenate(string &senate, vector<bool> &rightremoved, int i) {
        int n = senate.size();
        for(int k=i+1; k<i+n; k++) {
            if(senate[k%n] != senate[i] && !rightremoved[k%n]) return k%n;
        }
        return -1;
    }
    string getSenateName(string &senate, int i) {
        return senate[i]=='R'?"Radiant":"Dire";
    }
    string predictPartyVictory(string senate) {
        vector<bool> rightremoved(senate.size(), false);
        int i = 0, n = senate.size();
        while(true) {
            if(!rightremoved[i]) {
                int nextoppositesenateidx = findnextoppavailablesenate(senate, rightremoved, i);
                if(nextoppositesenateidx == -1) return getSenateName(senate, i);
                else {
                    rightremoved[nextoppositesenateidx] = true;
                }
            }
            i = (i+1)%n;
        }
        return "";
    }
};