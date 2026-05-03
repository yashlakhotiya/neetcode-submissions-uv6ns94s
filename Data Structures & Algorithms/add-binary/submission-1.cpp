class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        if(a.size() < b.size()) swap(a,b);
        vector<int> sumvector(a.size()+1, 0);
        for(int i=0; i<b.size(); i++) {
            int n1 = a[i]-'0', n2 = b[i]-'0';
            int sum = n1+n2+carry;
            int digit = sum%2;
            carry = sum/2;
            sumvector[i] = digit;
        }
        for(int i=b.size(); i<a.size(); i++) {
            int n1 = a[i]-'0';
            int sum = n1+carry;
            int digit = sum%2;
            carry = sum/2;
            sumvector[i] = digit;
        }
        sumvector[a.size()] = carry;
        stringstream ss;
        int i=sumvector.size()-1;
        while(i >= 0 && sumvector[i] == 0) i--;
        while(i >= 0) ss << sumvector[i--];
        return ss.str()==""?"0":ss.str();
    }
};