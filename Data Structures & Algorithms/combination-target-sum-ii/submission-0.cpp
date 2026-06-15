class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx, vector<int> path, int cur, vector<int>& candidates, int target){
        if(cur == target){
            ans.push_back(path);
            return;
        }

        int n = candidates.size();
        for(int  i= idx; i < n; i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            if(cur + candidates[i] > target){
                break;
            }

            path.push_back(candidates[i]);
            dfs(i+1, path, cur + candidates[i], candidates, target);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return ans;
    }
};
