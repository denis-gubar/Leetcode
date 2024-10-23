class Twitter {
public:
    struct Queue
    {
        int data[11];
        char L, R, size;
        Queue() : L(0), R(0), size(0)
        {
        }
        void add(int x)
        {
            if (size == 10)
                L = (L + 1) % 11;
            else
                ++size;
            data[R] = x;
            R = (R + 1) % 11;
        }
    };
    short time;
    unique_ptr<Queue[]> Q;
    unique_ptr<unordered_set<short>[]> F;
    Twitter(): time(0), Q(new Queue[501]), F(new unordered_set<short>[501]) {
    }

    void postTweet(int userId, int tweetId) {
        Q[userId].add((time << 15) | tweetId);
        ++time;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        result.reserve(10);
        auto comp = [this](pair<short, short> a, pair<short, short> b) -> bool
            {
                return Q[a.first].data[a.second] < Q[b.first].data[b.second];
            };
        priority_queue<pair<short, short>, vector<pair<short, short>>, decltype(comp)> PQ(comp);
        if (Q[userId].size > 0)
            PQ.push({ userId, (Q[userId].R + 10) % 11 });
        for(int f : F[userId])
            if (Q[f].size > 0)
                PQ.push({ f, (Q[f].R + 10) % 11 });
        while (!PQ.empty())
        {
            pair<short, short> P = PQ.top(); PQ.pop();
            short const& uId = P.first;
            short const& it = P.second;
            result.push_back(Q[uId].data[it] & ((1 << 15) - 1));
            if (result.size() == 10)
                break;
            if (it == Q[uId].L)
                continue;
            PQ.push({ uId, (it + 10) % 11 });
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        F[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        unordered_set<short>& S = F[followerId];
        if (auto it = S.find(followeeId); it != S.end())
            S.erase(it);
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
