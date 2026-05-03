class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(num1.size()+num2.size(), 0);
        for(int i=0; i<num1.size(); i++) {
            for(int j=0; j<num2.size(); j++) {
                int n1 = num1[i]-'0';
                int n2 = num2[j]-'0';
                int prod = n1*n2;
                int sum = res[i+j]+prod;
                res[i+j+1] += sum/10;
                res[i+j] = sum%10;
            }
        }
        stringstream result;
        int i = res.size()-1;
        while(i >= 0 && res[i] == 0) i--;
        while(i >= 0) {
            result << res[i--];
        }
        return result.str();
    }
};
