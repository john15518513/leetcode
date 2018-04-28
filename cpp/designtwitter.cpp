class Twitter {
    struct Tweet
    {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };
    struct cmp {
        bool operator()(const pair<list<Tweet>::iterator, int> &a, const pair<list<Tweet>::iterator, int> &b) const {
            return a.first->time < b.first->time;
        }  
    };
public:
    /** Initialize your data structure here. */
    Twitter(): time(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        post[userId].push_front(Tweet(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<list<Tweet>::iterator, int>> Mh;
        // push userId post in Mh
        if (!post[userId].empty())
            Mh.push_back(make_pair(post[userId].begin(), userId));
        for (auto &m: followers[userId]) {
            if (!post[m].empty())
                Mh.push_back(make_pair(post[m].begin(), m));
        }
        
        make_heap(Mh.begin(), Mh.end(), cmp());
        
        int cnt = 10;
        vector<int> res;
        while (cnt > 0 and !Mh.empty()) {
            res.push_back(Mh.front().first->id);
            auto it = Mh.front().first;
            auto eit = Mh.front().second;
            pop_heap(Mh.begin(), Mh.end(), cmp());
            Mh.pop_back();
            if (++it != post[eit].end()) {
                Mh.push_back(make_pair(it, eit));
                push_heap(Mh.begin(), Mh.end(), cmp());
            }
            cnt--;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
private:
    int time;
    unordered_map<int, list<Tweet>> post;
    unordered_map<int, unordered_set<int>> followers;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
