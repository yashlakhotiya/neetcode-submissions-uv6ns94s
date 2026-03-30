class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int maxi = 0;
        int curr = 0;
        int l = 0;
        for(char c : s) {
            if(!st.count(c)){
                st.insert(c);
                curr++;
                maxi = max(curr,maxi);
            } else {
                while(!st.empty() && st.count(c)) {
                    st.erase(s[l++]);
                    curr--;
                }
                st.insert(c);
                curr++;
            }
        }
        return maxi;
    }
};
