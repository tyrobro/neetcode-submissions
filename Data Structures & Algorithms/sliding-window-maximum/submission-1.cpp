class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = nums[0];
        rightMax[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            if(i%k==0){
                leftMax[i] = nums[i];
            } else {
                leftMax[i] = max(leftMax[i-1], nums[i]);
            }

            if((n-i-1)%k == 0){
                rightMax[n-i-1] = nums[n-i-1];
            } else {
                rightMax[n-1-i] = max(rightMax[n-i], nums[n-i-1]);
            }
        }

        vector<int> ans(n-k+1);
        for(int i = 0; i < n-k+1; i++){
            ans[i] = max(leftMax[i+k-1], rightMax[i]);
        }
        
        return ans;
    }
};
