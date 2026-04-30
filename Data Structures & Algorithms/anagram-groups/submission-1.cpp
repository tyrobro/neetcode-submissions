class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, string>> collection;

        for(auto &s : strs)
        {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            collection.push_back({sorted, s});
        }

        sort(collection.begin(), collection.end());

        vector<vector<string>> result;
        vector<string> currentGroup;
        string prevKey = "";
        for(auto &p: collection){
            if(p.first != prevKey){
                if(!currentGroup.empty()){
                    result.push_back(currentGroup);
                    currentGroup.clear();
                }
                prevKey = p.first;
            }
            currentGroup.push_back(p.second);
        }
        if(!currentGroup.empty())
        {
            result.push_back(currentGroup);
        }
        return result;

    }
};
