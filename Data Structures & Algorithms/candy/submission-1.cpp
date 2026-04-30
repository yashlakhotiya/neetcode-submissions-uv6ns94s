class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for(int i=0; i<ratings.size(); i++) {
            vector<int> tempcandies(candies.begin(), candies.end());
            for(int j=0; j<ratings.size(); j++) {
                if(j == 0) {
                    if(ratings[j] > ratings[j+1] && candies[j] <= candies[j+1]) tempcandies[j] = candies[j+1]+1; 
                } else if (j == ratings.size()-1) {
                    if(ratings[j] > ratings[j-1] && candies[j] <= candies[j-1]) tempcandies[j] = candies[j-1]+1; 
                } else {
                    if(ratings[j] > ratings[j+1] && candies[j] <= candies[j+1]) tempcandies[j] = max(tempcandies[j], candies[j+1]+1); 
                    if(ratings[j] > ratings[j-1] && candies[j] <= candies[j-1]) tempcandies[j] = max(tempcandies[j], candies[j-1]+1);
                }
            }
            candies = tempcandies;
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};