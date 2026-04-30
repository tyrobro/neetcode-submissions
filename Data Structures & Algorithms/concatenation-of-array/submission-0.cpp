class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(2*len);
        for(int i = 0; i < 2*len; i++)
        {
            if(i < len)
            {
                ans[i] = nums[i];
            }
            else
            {
                ans[i] = nums[i - len];
            }
        }
        return ans;
    }
};