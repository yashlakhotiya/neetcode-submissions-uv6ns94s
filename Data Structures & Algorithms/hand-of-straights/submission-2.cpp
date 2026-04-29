class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;
        unordered_map<int,int> mp;
        for(int card: hand) mp[card]++;
        sort(hand.begin(), hand.end());
        for(int num: hand) {
            if(mp[num] > 0) {
                for(int i=num; i<num+groupSize; i++) {
                    if(mp[i] == 0) return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
