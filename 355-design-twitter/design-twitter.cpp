class Twitter {
public:
int time ;

//user id nnumber of follows
unordered_map<int,unordered_set<int>>Followee;
unordered_map<int,vector<pair<int,int>>>post;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxheap;
         for (auto &p : post[userId]) {
            maxheap.push(p);
        }


        for(auto f : Followee[userId])
        {
            for(auto p:post[f])
            {
                maxheap.push(p);
            }
        }

        int cnt =10;
        vector<int>feed;
        while(!maxheap.empty() && cnt > 0){
            feed.push_back(maxheap.top().second);
            maxheap.pop();
            cnt--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        Followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        Followee[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */