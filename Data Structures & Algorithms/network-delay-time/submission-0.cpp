class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for(const auto& t: times){
            edges[t[0]].emplace_back(t[1], t[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        set<int> visited;
        int t = 0;
        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int w1 = curr.first;
            int n1 = curr.second;
            if(visited.count(n1)){
                continue;
            }
            visited.insert(n1);
            t = w1;

            if(edges.count(n1)){
                for(const auto& next: edges[n1]){
                    int n2 = next.first;
                    int w2 = next.second;

                    if(!visited.count(n2)){
                        minHeap.push({w1 + w2, n2});
                    }
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
