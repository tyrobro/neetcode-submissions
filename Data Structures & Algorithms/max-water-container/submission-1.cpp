class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int cap = INT_MIN;
        int l = 0;
        int r= n-1;

        while(l < r){
            cap = max(cap, min(heights[l], heights[r])*(r - l));
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }

        return cap;

    }
};
