class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        int sum = 0;
        for(string op : operations) {
            if(op == "+") {
                int j = scores.size()-1;
                if(j >= 0 && j-1 >= 0) {
                    sum += scores[j]+scores[j-1];
                    scores.push_back(scores[j]+scores[j-1]);
                }
            } else if(op == "D") {
                int j = scores.size()-1;
                if(j >= 0) {
                    sum += 2*scores[j];
                    scores.push_back(2*scores[j]);
                }
            } else if(op == "C"){
                int j = scores.size()-1;
                if(j >= 0) {
                    sum -= scores[j];
                    scores.pop_back();
                }
            } else {
                sum += stoi(op);
                scores.push_back(stoi(op));
            }
        }
        return sum;
    } 
};