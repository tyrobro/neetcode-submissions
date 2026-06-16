class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(0, {}, nums);
        return ans;
    }

    void helper(int i, vector<int> subset, vector<int>& nums){
        ans.push_back(subset);
        int n = nums.size();

        for(int j = i; j < n; j++){
            if(j > i && nums[j] == nums[j-1]){
                continue;
            }

            subset.push_back(nums[j]);
            helper(j+1, subset, nums);
            subset.pop_back();
        }
    }
};
