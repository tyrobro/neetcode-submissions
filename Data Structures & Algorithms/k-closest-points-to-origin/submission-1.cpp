class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        for(auto& x: points){
            int x1 = x[0];
            int y1 = x[1];

            int dist = x1*x1 + y1*y1;
            maxHeap.push({dist, {x1, y1}});
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> ans;
        while(!maxHeap.empty()) {
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return ans;
    }
};
