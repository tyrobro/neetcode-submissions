class Twitter {
public:
    int count;
    unordered_map<int, vector<pair<int, int>>> twM;
    unordered_map<int, unordered_set<int>> foM;

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        twM[userId].push_back({count, tweetId});
        
        if (twM[userId].size() > 10){
            twM[userId].erase(twM[userId].begin());
        }

        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        foM[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        if(foM[userId].size() >= 10) {
            priority_queue<vector<int>> maxHeap;
            for(auto f: foM[userId]){
                if(!twM.count(f)) continue;
                int idx = twM[f].size()-1;
                auto &p = twM[f][idx];
                maxHeap.push({-p.first, p.second, f, idx - 1});

                if(maxHeap.size() > 10) maxHeap.pop();
            }

            while(!maxHeap.empty()) {
                auto t = maxHeap.top();
                maxHeap.pop();
                minHeap.push({-t[0], t[1], t[2], t[2]});
            }
        }
        else {
            for(auto f : foM[userId]) {
                if(!twM.count(f)) continue;
                int idx = twM[f].size() - 1;
                auto &p = twM[f][idx];
                minHeap.push({p.first, p.second, f, idx-1});
            }
        }

        while (!minHeap.empty() && ans.size() < 10) {
            auto t = minHeap.top();
            minHeap.pop();
            ans.push_back(t[1]);
            int idx = t[3];
            if (idx >= 0) {
                auto &p = twM[t[2]][idx];
                minHeap.push({p.first, p.second, t[2], idx - 1});
            }
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        foM[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (foM[followerId].count(followeeId)) {
            foM[followerId].erase(followeeId);
        }
    }
};
