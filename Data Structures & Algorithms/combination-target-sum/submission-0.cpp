class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> cur, int total, vector<int>& nums, int target){
        if(total == target){
            ans.push_back(cur);
            return;
        }
        int n = nums.size();
        for(int j =i; j < n; j++){
            if(total + nums[j] > target){
                return;
            }

            cur.push_back(nums[j]);
            dfs(j, cur, total+nums[j], nums, target);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, 0, nums, target);
        return ans;
    }
};
