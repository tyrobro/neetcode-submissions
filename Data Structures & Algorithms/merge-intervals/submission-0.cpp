class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        
        for(auto& interval: intervals){
            mp[interval[0]]++;
            mp[interval[1]]--;
        }

        vector<vector<int>> ans;
        vector<int> interval;
        int active = 0;
        for(const auto& [i, count] : mp){
            if(interval.empty()){
                interval.push_back(i);
            }
            active += count;
            if(active == 0){
                interval.push_back(i);
                ans.push_back(interval);
                interval.clear();
            }
        }

        return ans;

    }
};
