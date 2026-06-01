class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        int n = piles.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            r = max(r, piles[i]);
        }

        while(l <= r){
            int mid = l + (r - l)/2;
            long long time = 0;

            for(auto x: piles){
                time += ceil(static_cast<double>(x)/mid);
            }

            if(time <= h){
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return ans;

    }
};
