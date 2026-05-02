class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(visited.count(n) == 0) {
            visited.insert(n);
            int num = n;
            int sum = 0;
            while(num != 0) {
                int digit = num%10;
                sum += digit*digit;
                num /= 10;
            }
            n = sum;
            if(n == 1) return true;
        }
        return false;
    }
};
