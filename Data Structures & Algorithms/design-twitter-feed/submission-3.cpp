class Twitter {
    unordered_map<int, unordered_set<int>> Followers;
    queue<pair<int, int>> Tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        Tweets.push({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        stack<int> res_stack;
        queue<pair<int, int>> tweets = Tweets;

        while(!tweets.empty()){
            auto [u, t] = tweets.front();
            tweets.pop();

            if(u == userId || Followers[userId].count(u) > 0){
                res_stack.push(t);
            }
        }
        vector<int> res;

        while(res.size() < 10 && !res_stack.empty()){
            res.push_back(res_stack.top());
            res_stack.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        Followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(Followers[followerId].count(followeeId) > 0){
            Followers[followerId].erase(followeeId);
        }
    }
};
