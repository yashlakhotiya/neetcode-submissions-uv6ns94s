class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int MIN = -pow(2,31), MAX=pow(2,31)-1;
        while(x!=0) {
            int digit = x%10;
            x /= 10;
            if(res > MAX/10 || (res==MAX/10 && digit > MAX%10)) return 0;
            else if(res < MIN/10 || (res == MIN/10 && digit < MIN%10)) return 0;
            res = res*10+digit;
        }
        return res;
    }
};
