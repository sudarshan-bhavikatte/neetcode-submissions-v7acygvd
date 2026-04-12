class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int count = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> feed = tweets[userId];

        for(int followeeId : followers[userId]){
            feed.insert(feed.end(),tweets[followeeId].begin(),tweets[followeeId].end());
        }
        sort(feed.begin(),feed.end(), [](auto &a,auto &b){
            return a.first > b.first;
        });

        vector<int> res;

        for(int i=0; i<10 && i<feed.size();i++){
            res.push_back(feed[i].second);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].find(followeeId) != followers[followerId].end()){
            followers[followerId].erase(followeeId);
        }
    }
};
