class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = l + k;
        int n = nums.size();
        vector<int> ans;
        while(r <= n){
            int maxNum = INT_MIN;
            for(int i = l; i < r; i++){
                maxNum = max(maxNum, nums[i]);
            }
            ans.push_back(maxNum);
            l++;
            r++;
        }
        return ans;
    }
};
