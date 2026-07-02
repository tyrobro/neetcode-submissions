class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        
        vector<int> sortedQ = queries;
        sort(sortedQ.begin(), sortedQ.end());
        map<int, int> ans;

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] >b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        int i = 0;
        for (int q : sortedQ) {
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                minHeap.push({r - l + 1, r});
                i++;
            }

            while (!minHeap.empty() && minHeap.top()[1] < q) {
                minHeap.pop();
            }

            ans[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }

        vector<int> result(queries.size());
        for (int j = 0; j < queries.size(); j++) {
            result[j] = ans[queries[j]];
        }
        return result;
    }
};
