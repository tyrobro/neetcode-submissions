class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(helper(nums) %2 != 0){
            return false;
        }

        int target = helper(nums)/2;
        vector<bool> dp(target+1, false);
        int n= nums.size();
        dp[0] = true;
        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }

    int helper(vector<int>& nums){
        int total = 0;
        for(int num: nums){
            total += num;
        }
        return total;
    }
};
