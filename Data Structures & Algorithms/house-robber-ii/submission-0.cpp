class Solution {
public:
    vector<vector<int>> memo;
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        memo.resize(n, vector<int>(2, -1));
        return max(dfs(0, 1, nums), dfs(1, 0, nums));
    }

    int dfs(int i, int flag, vector<int>& nums){
        int n = nums.size();
        if(i >= n || (flag == 1 && i== n-1)){
            return 0;
        }

        if(memo[i][flag] != -1) return memo[i][flag];

        memo[i][flag] = max(dfs(i+1, flag, nums), nums[i] + dfs(i+2, flag | (i==0 ? 1:0), nums));
        return memo[i][flag];
    }
};
