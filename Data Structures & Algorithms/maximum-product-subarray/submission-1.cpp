class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int curMin = 1;
        int curMax = 1;

        for(int i : nums){
            int temp = curMax * i;
            curMax = max(max(i*curMax, i * curMin), i);
            curMin = min(min(temp, i*curMin), i);
            ans = max(ans, curMax);
            }

            return ans;
    }
};
