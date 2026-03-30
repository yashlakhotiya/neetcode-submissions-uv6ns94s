struct Tweet {
    int tweetId;
    int timestamp;
    Tweet(int tweetId, int ts) : tweetId(tweetId), timestamp(ts) {}
};

struct cmp {
    bool operator()(Tweet *a, Tweet *b) {
        return a->timestamp > b->timestamp;
    }
};

class Twitter {
    int ts=0;
    unordered_map<int, set<int>> followmp;
    unordered_map<int, vector<Tweet*>> tweetmp;
public:
    Twitter() {
        ts=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmp[userId].push_back(new Tweet(tweetId, ts));
        if(tweetmp[userId].size() > 10) tweetmp[userId].erase(tweetmp[userId].begin());
        ts++;
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> followers;
        if(followmp.count(userId)) followers = followmp[userId];
        followers.insert(userId);
        priority_queue<Tweet*, vector<Tweet*>, cmp> pq;
        for(int followerId: followers) {
            if(tweetmp.count(followerId)){
                for(auto tweet : tweetmp[followerId]) {
                    pq.push(tweet);
                    if(pq.size()>10) pq.pop();
                }
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            res.push_back(top->tweetId);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmp[followerId].erase(followeeId);
    }
};

