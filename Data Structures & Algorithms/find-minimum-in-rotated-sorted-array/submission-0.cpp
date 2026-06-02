class Solution {
public:
    int findMin(vector<int> &nums) {
        int n= nums.size();
        int r = n-1;
        int l = 0;
        int ans = nums[0];
        while(l <= r){
            if(nums[l] < nums[r]){
                ans = min(ans, nums[l]);
                break;
            }
            
            int mid = l + (r-l)/2;
            ans = min(ans, nums[mid]);

            if(nums[mid] >= nums[l]){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return ans;
    }
};
