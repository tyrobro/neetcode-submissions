class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int total = 1;
        for(int i =0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(j == i){
                    continue;
                } 
                total *= nums[j];
            }
            ans.push_back(total);
            total = 1;
        }

        return ans;
    }
};
