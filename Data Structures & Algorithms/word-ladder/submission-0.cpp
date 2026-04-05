class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        while(!q.empty()) {
            int qsize = q.size();
            for(int i=0; i<qsize; i++) {
                auto &[curword, dist] = q.front(); q.pop();
                visited.insert(curword);
                if(curword == endWord) {
                    return dist;
                }
                for(int i=0; i<curword.size(); i++) {
                    string nextword = curword;
                    char curchar = nextword[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(c == curchar) continue;
                        nextword[i] = c;
                        if(!visited.count(nextword) && wordset.count(nextword)) q.push({nextword, dist+1});
                    }
                }
            }
        }
        return 0;
    }
};
