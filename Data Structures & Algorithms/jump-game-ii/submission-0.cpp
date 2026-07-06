class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int l = 0;
        int r =0;
        int n = nums.size();
        while(r < n-1){
            int door = 0;
            for(int i = l; i <= r; i++){
                door = max(door, i + nums[i]);
            }
            l = r + 1;
            r = door;
            ans++;
        }

        return ans;
    }
};
