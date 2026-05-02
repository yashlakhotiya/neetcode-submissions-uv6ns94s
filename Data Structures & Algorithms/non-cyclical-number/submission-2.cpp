class Solution {
public:
    int sumofdigitsq(int num) {
        int sum = 0;
        while(num != 0) {
            int digit = num%10;
            sum += digit*digit;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = sumofdigitsq(n), slow = n;
        while(fast != 1 && fast != slow) {
            fast = sumofdigitsq(sumofdigitsq(fast));
            slow = sumofdigitsq(slow);
        }
        return fast == 1;
    }
};
