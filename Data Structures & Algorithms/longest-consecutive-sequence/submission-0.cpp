class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxLen = 1;
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // Skip duplicates
                continue;
            } 
            else if (nums[i] == nums[i - 1] + 1) {
                // Consecutive number → extend current streak
                count++;
            } 
            else {
                // Break in the sequence → reset count
                maxLen = max(maxLen, count);
                count = 1;
            }
        }

        // Final check in case longest streak is at the end
        return max(maxLen, count);
    }
};