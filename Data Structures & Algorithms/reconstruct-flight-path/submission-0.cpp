class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for(auto& ticket: tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [src, dests]: adj){
            sort(dests.rbegin(), dests.rend());
        }

        vector<string> ans;
        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(const string& src, unordered_map<string, deque<string>>& adj, vector<string>& ans){
        while(!adj[src].empty()){
            string end = adj[src].back();
            adj[src].pop_back();
            dfs(end, adj, ans);
        }

        ans.push_back(src);
    }
};
