struct Tweet {
    int userId;
    int tweetId;
    int timeStamp;
    // static bool Asc(const Tweet& a, const Tweet& b){
    //     return a.time > b.time
    // }
    bool operator < (const Tweet& t) const{
        return timeStamp > t.timeStamp;  
    }
};

class Twitter {
private:
    map<int, set<int> > userRelation;
    set<Tweet> tweets;
    int timeStamp;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timeStamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet tmp_tweet = {userId, tweetId, timeStamp++}; 
        tweets.insert(tmp_tweet);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        set<int> followUsers = userRelation[userId]; 
        int i = 0;
        auto itr = tweets.begin();
        while (i < 10 && itr != tweets.end()) {
            if(followUsers.find(itr->userId) != followUsers.end() || userId == itr->userId){
                newsFeed.push_back(itr->tweetId);
                i++;
            }
            itr++;
        }
        return newsFeed;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        userRelation[followerId].insert(followeeId);    
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        userRelation[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */