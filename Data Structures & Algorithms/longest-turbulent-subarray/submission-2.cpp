class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        char state = 'N'; // 'I', 'D'
        int L=1, maxl=1, p=arr[0];
        for(int i=1; i<arr.size(); i++) {
            int el = arr[i];
            if(el == p) {
                L = 1;
                state = 'N';
                p = el;
                continue;
            }
            if(state == 'N') {
                L++;
                maxl = max(maxl, L);
                if(el > p) state = 'I';
                else state = 'D';
                p = el;
            } else if(state == 'D') {
                if(el < p) {
                    L = 2;
                    maxl = max(maxl, L);
                    p = el;
                } else {
                    L++;
                    maxl = max(maxl, L);
                    p = el;
                    state = 'I';
                }
            } else if(state == 'I') {
                if(el > p) {
                    L = 2;
                    maxl = max(maxl, L);
                    p = el;
                } else {
                    L++;
                    maxl = max(maxl, L);
                    p = el;
                    state = 'D';
                }
            }
        }
        return maxl;
    }
};