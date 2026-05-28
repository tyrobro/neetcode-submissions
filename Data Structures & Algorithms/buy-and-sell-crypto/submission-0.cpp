class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int ans = 0;
        for(int x: prices){
            ans = max(ans, x - minPrice);
            minPrice = min(minPrice, x);
        }
        return ans;
    }
};
