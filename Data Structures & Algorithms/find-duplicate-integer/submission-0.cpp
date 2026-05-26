class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        for(auto y: mp){
            if(y.second> 1){
                return y.first;
            }
        }
        return 0;
    }
};
