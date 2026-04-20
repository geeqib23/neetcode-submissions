class Twitter {
    unordered_map<int, unordered_set<int>> followeeMap;
    unordered_map<int, vector<pair<int,int>> > tweetMap;
    int count;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto followees = followeeMap[userId];
        followees.insert(userId);
        set<pair<int,int>> recentTweets;
        for(auto &f:followees){
            cout << f << endl;
            auto tweets = tweetMap[f];
            int c = 0;
            for(int i = tweets.size()-1;i>=0;i--){
                if(c>10) break;
                // cout << tweets[i].first << " " << tweets[i].second << endl;
                if(recentTweets.size()<10)
                    recentTweets.insert(tweets[i]);
                else{
                    auto it = recentTweets.begin();
                    if((tweets[i].first> it->first)){
                        recentTweets.erase(it);
                        recentTweets.insert(tweets[i]);
                    }
                }
                c++;
            }
        } 
        vector<int> res;
        for(auto &[counter,tweetId]:recentTweets){
            res.push_back(tweetId);
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followeeMap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followeeMap[followerId].erase(followeeId);
    }
};
