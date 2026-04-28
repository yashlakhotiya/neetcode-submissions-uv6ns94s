class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecnt=0, tencnt=0, twentycnt=0;
        for(int bill: bills) {
            switch (bill) {
                case 5:
                    fivecnt++;
                    break;
                case 10:
                    if(fivecnt == 0) return false;
                    fivecnt--;
                    tencnt++;
                    break;
                case 20:
                    if(!(fivecnt >= 3 || (fivecnt >= 1 && tencnt >= 1))) return false;
                    if(fivecnt >= 1 && tencnt >= 1) {
                        fivecnt--; tencnt--;
                    } else if(fivecnt >= 3) {
                        fivecnt -= 3;
                    }
                    break;
            }
        }
        return true;
    }
};